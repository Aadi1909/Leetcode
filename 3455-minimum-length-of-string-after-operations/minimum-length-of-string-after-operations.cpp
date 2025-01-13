class Solution {
public:
    int minimumLength(string s) {
        std::unordered_map<char, int> mp;
        for(char& c : s){
            mp[c]++;
        }
        int extra = 0;
        for(auto& m : mp){
            if(m.second > 1){
                if(m.second  % 2 == 1) extra += 1;
                else extra += 2;
            }
            else extra++;
        }
        return extra;
    }
};
