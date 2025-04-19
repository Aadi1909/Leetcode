class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, 
                                          vector<vector<int>>& friends, 
                                          int id, int level) {
        int n = friends.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(id);
        visited[id] = true;
        int currLevel = 0;
        while (!q.empty() && currLevel < level) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int u = q.front(); q.pop();
                for (int v : friends[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            currLevel++;
        }
        unordered_map<string, int> freq;
        while (!q.empty()) {
            int friendId = q.front(); q.pop();
            for (const string& video : watchedVideos[friendId]) {
                freq[video]++;
            }
        }
        vector<pair<string, int>> videos(freq.begin(), freq.end());
        sort(videos.begin(), videos.end(), [](auto& a, auto& b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });
        vector<string> result;
        for (auto& [video, _] : videos) {
            result.push_back(video);
        }
        return result;
    }
};
