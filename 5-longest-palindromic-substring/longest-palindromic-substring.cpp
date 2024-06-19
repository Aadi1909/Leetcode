class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string res = "";
        int max_len = 0;
        for(int i = 0; i < n; ++i){
            int low = i, hi = i;
            while(low >= 0 and hi < n and s[low] == s[hi]){
                int len = hi - low + 1;
                if(len > max_len){
                    max_len = len;
                    res = s.substr(low, len);
                }
                low--;
                hi++;
            }
        }
        for(int i = 0; i < n - 1; ++i){
            int low = i, hi = i + 1;
            while(low >= 0 and hi < n and s[low] == s[hi]){
                int len = hi - low + 1;
                if(len > max_len){
                    max_len = len;
                    res = s.substr(low, len);
                }
                low--;
                hi++;
            }
        }
        return res;
    }
};