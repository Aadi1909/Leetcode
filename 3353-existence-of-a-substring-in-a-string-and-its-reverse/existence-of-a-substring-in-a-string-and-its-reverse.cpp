class Solution {
public:
    bool isSubstringPresent(string s) {
        for(int i = 1; i < s.length(); i++){
            if(s[i] == s[i-1])return true;
        }
        string t = s;
        reverse(t.begin(), t.end());
        for(int i = 0; i < s.length() - 1; i++){
            if(t.find(s.substr(i, 2)) != string::npos) return true;
        }
        
        return false;
    }
};