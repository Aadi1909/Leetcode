class Solution {
public:
    string removeStars(string s) {
        string a_s;
        for(int i = 0; i < s.length(); ++i) {
            if (s[i] != '*') a_s += s[i];
            else {
                int count = 0;
                int j = i;
                while (s[j] == '*' && j < s.length()) {
                    count++;
                    j++;
                }
                while (count--){
                    a_s.pop_back();
                }
                i = j - 1;
            }
        }
        return a_s;
    }
};