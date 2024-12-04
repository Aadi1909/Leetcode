class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int  j = 0;
        for(int i = 0; i < str1.size(); i ++){
            if(str2[j] == str1[i] || int(str2[j] - str1[i] + 26) % 26 == 1){
                j++;
                if(j == str2.size()) return true;
            }
        }
        return false;
    }
};