class dsu {
private:
    vector<int> parent, rank;
    int n;
public:
    explicit dsu(int _n) : n(_n) {
        parent.resize(n);
        rank.resize(n ,0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int v) {
        if (parent[v] == v) {
            return v;
        }
        return parent[v] = find(parent[v]);
    }
    void make(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) {
                swap(a, b);
            }
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& arr) {
        dsu uf(arr.size() + 1);
        int answer = arr.size();
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = 0; j < arr[i].size(); ++j) {
                if (arr[i][j]) {
                    if (uf.find(i + 1) != uf.find(j + 1)) {
                        uf.make(i + 1, j + 1);
                        answer--;
                    }
                }
            }
        }
        return answer;
    }
};