

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& x) {
        //こにちは
        //元気だよ
        // when the transition is possible from one node to another and 
        // what is the cost for that node transition
        // also find out how to map the strings from the wordlist

        unordered_set<string> wordSet(x.begin(), x.end());
        if (!wordSet.count(endWord)) return 0;
        auto ok = [&](const string& src, const string& adj) {
            if (src.length() != adj.length()) return false;
            int count = 0;
            for (int i = 0; i < src.length(); ++i) {
                if (src[i] != adj[i]) count++;
                if (count > 1) return false;
            }
            return count == 1;
        };
        unordered_map<string, vector<string>> g;
        for (int i = 0; i < x.size(); ++i) {
            for (int j = i + 1; j < x.size(); ++j) {
                if (ok(x[i], x[j])) {
                    g[x[i]].push_back(x[j]);
                    g[x[j]].push_back(x[i]);
                }
            }
        }
        for (const auto& word : x) {
            if (ok(beginWord, word)) g[beginWord].push_back(word);
        }
        auto bfs = [&]() -> int {
            unordered_map<string, int> cost;
            queue<string> q;
            cost[beginWord] = 1;
            q.push(beginWord);
            while (!q.empty()) {
                string adj = q.front();
                q.pop();
                if (adj == endWord) return cost[endWord];
                for (const auto& i : g[adj]) {
                    if (!cost.count(i)) {
                        cost[i] = cost[adj] + 1;
                        q.push(i);
                    }
                }
            }
            return 0;
        };
        return bfs();
    }
};
