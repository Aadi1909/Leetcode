class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = -1;
        int curr = 0, maxLen = 0;
        vector<bool> set(256, 0);
        while(i < s.length()){
            int ch = s[i];
            while(set[ch] == true){
                j++;
                int rm = s[j];
                set[rm] = false;
            }
            set[ch] = true;
            curr = i - j;
            maxLen = max(maxLen, curr);
            i++;
        }
        return maxLen;
    }
};
