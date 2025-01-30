class dsu {
public:
    vector<int> parent, rank;
    int n;

    dsu(int _n) : n(_n) {
        parent.resize(n + 1);  // Cities are labeled from 1 to n
        rank.resize(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int v) {
        if (v == parent[v])
            return v;
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
            if (rank[a] == rank[b]) {
                rank[a]++;
            }
        }
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int answer = 1e9;
        dsu uf(n);
        for (int i = 0; i < roads.size(); ++i) {
            if (uf.find(roads[i][0]) != uf.find(roads[i][1])) {
                uf.make(roads[i][0], roads[i][1]);
            }
        }
        int one = uf.find(1);
        for (int i = 0; i < roads.size(); ++i) {
            if (uf.find(roads[i][0]) == one && uf.find(roads[i][1]) == one) {
                answer = min(answer, roads[i][2]);
            }
        }
        return answer;
    }
};