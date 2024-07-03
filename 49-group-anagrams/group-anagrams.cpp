class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, string>> modified(strs.size());
        for(int i = 0; i < strs.size(); ++i) {
            modified[i].second = strs[i];
            sort(strs[i].begin(), strs[i].end());
            modified[i].first = strs[i];
        }
        sort(modified.begin(), modified.end());
        vector<vector<string>> answer;
        vector<string> temp;
        string curr = modified[0].first;
        temp.push_back(modified[0].second);
        for (int i = 1; i < strs.size(); ++i) {
            if (modified[i].first == curr) {
                temp.push_back(modified[i].second);
            }
            else {
                answer.push_back(temp);
                temp.clear();
                temp.push_back(modified[i].second);
                curr = modified[i].first;
            }
        }
        if(temp.size() > 0) answer.push_back(temp);
        return answer;
    }
};