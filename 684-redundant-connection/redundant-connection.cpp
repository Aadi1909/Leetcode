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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> answer;
        dsu uf(edges.size() + 1);
        for (int i = 0; i < edges.size(); ++i) {
            if (uf.find(edges[i][0]) == uf.find(edges[i][1])) {
                answer.push_back({edges[i][0], edges[i][1]});
                continue;
            }
            uf.make(edges[i][0], edges[i][1]);
        }
        return answer.back();
    }
};