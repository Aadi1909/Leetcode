class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.length()) return false;
        std::vector<int> rem;
        std::unordered_map<char, int> mp;
        for(int i = 0; i < s.length(); ++i){
            mp[s[i]]++;
        }
        bool last = false;
        int count = 0;
        for(auto& it : mp){
            if(it.second % 2 == 1){
                rem.push_back(it.first);
                it.second--;
            }
        }
        return rem.size() > k ? false : true;
    }
};