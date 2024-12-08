// -----> dfs


class Solution {

public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
    vector<double>& values,  vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0], v = equations[i][1];
            graph[u].push_back({v, values[i]});
            graph[v].push_back({u, 1.0 / values[i]});
        }
        vector<double> results;
        function<double(string, string, unordered_set<string>&)> dfs = [&](string src, string dest, unordered_set<string>& visited) {
            if (graph.find(src) == graph.end() || graph.find(dest) == graph.end()) return -1.0;
            if (src == dest) return 1.0;
            visited.insert(src);
            for (auto& neighbor : graph[src]) {
                if (visited.count(neighbor.first)) continue;
                double result = dfs(neighbor.first, dest, visited);
                if (result != -1.0) {
                    return result * neighbor.second;
                }
            }
            return -1.0;
        };
        for (auto& query : queries) {
            unordered_set<string> visited;
            results.push_back(dfs(query[0], query[1], visited));
        }

        return results;
    }
};


// ----> bfs

/*

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
                                 vector<double>& values, 
                                 vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;

        // Build the graph
        for (int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0], v = equations[i][1];
            graph[u].push_back({v, values[i]});
            graph[v].push_back({u, 1.0 / values[i]});
        }

        vector<double> results;

        // Helper function for BFS
        auto bfs = [&](string start, string end) -> double {
            if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) 
                return -1.0;

            queue<pair<string, double>> q;
            unordered_set<string> visited;
            q.push({start, 1.0});  // Start node with weight 1.0
            visited.insert(start);

            while (!q.empty()) {
                auto [current, value] = q.front();
                q.pop();

                if (current == end) return value;

                for (auto& neighbor : graph[current]) {
                    if (!visited.count(neighbor.first)) {
                        visited.insert(neighbor.first);
                        q.push({neighbor.first, value * neighbor.second});
                    }
                }
            }
            return -1.0;  // No path found
        };

        // Process each query
        for (auto& query : queries) {
            results.push_back(bfs(query[0], query[1]));
        }

        return results;
    }
};

*/

