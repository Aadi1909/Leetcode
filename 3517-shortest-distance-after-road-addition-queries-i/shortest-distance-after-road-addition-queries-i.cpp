class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> queries) {
        vector<int> answer;
        vector<vector<int>> graph(n);
        for (int i = 0; i + 1 < n; ++i) {
            graph[i].push_back(i + 1);
        }
        auto bfs = [&](int targetNode) {
            queue<int> q;
            vector<int> distance(n, 0);
            vector<bool> visited(n, false);
            visited[0] = true;
            q.push(0);
            while (!q.empty()) {
                int currentNode = q.front();
                q.pop();
                if (currentNode == targetNode) {
                    return distance[currentNode];
                }
                for (int neighbor : graph[currentNode]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        distance[neighbor] = distance[currentNode] + 1;
                        q.push(neighbor);
                    }
                }
            }
            return 0;
        };
        for (const auto& query : queries) {
            int a = query[0];
            int b = query[1];
            graph[a].push_back(b);
            int shortestDistance = bfs(n - 1);
            answer.push_back(shortestDistance);
        }
        return answer;
    }
};