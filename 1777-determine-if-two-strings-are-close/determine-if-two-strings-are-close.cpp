class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) return false;
        vector<int> freq_f(26), freq_s(26);
        for(char w1 : word1) freq_f[w1 - 'a']++;
        for(char w2 : word2) freq_s[w2 - 'a']++;
        int f = 0, s = 0;
        bool ok = true;
        map<int, int> mp;
        for (int i = 0; i < 26; ++i) {
            if (freq_f[i] > 0 && freq_s[i] == 0) {
                return false;
            }
            if (freq_s[i] > 0 && freq_f[i] == 0) {
                return false;
            }
            mp[freq_s[i]]++;
            mp[freq_f[i]]--;
        }
        for (auto& m : mp) {
            if (m.second > 0) ok = false;
        }
        return ok ? true : false;
    }
};