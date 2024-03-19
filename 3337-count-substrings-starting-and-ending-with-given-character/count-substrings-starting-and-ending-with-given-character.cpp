class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count = 0;
        for(char S : s){
            if(S == c) {
                count++;
            }
        }
        long long res = count * (count + 1) / 2; 
        return res;
    }
};