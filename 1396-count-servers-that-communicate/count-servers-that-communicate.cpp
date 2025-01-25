class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};
class Solution {
public:
    int countServers(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int totalCells = n * m;
        UnionFind uf(totalCells);
        for (int i = 0; i < n; ++i) {
            int prev = -1;
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    if (prev != -1) {
                        uf.unionSets(i * m + prev, i * m + j);
                    }
                    prev = j;
                }
            }
        }
        for (int j = 0; j < m; ++j) {
            int prev = -1;
            for (int i = 0; i < n; ++i) {
                if (grid[i][j] == 1) {
                    if (prev != -1) {
                        uf.unionSets(prev * m + j, i * m + j);
                    }
                    prev = i;
                }
            }
        }
        std::unordered_map<int, int> componentSize;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    int root = uf.find(i * m + j);
                    componentSize[root]++;
                }
            }
        }
        int result = 0;
        for (const auto& [_, size] : componentSize) {
            if (size > 1) {
                result += size;
            }
        }
        return result;
    }
};

