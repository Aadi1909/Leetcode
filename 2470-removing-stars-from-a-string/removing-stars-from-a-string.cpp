class Solution {
public:
    string removeStars(string s) {
        string a_s;
        for(int i = 0; i < s.length(); ++i) {
            if (s[i] != '*') a_s += s[i];
            else {
                int j = i;
                while (s[j] == '*' && j < s.length()) {
                    a_s.pop_back();
                    j++;
                }
                i = j - 1;
            }
        }
        return a_s;
    }
};