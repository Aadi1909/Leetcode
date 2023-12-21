class Solution {
public:
    int maxVowels(string s, int k) {
        int cnt=0,mx=0;
        auto isVowel=[](char c) {
            return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
        };
        for(int i=0; i<k; i++){
            if(isVowel(s[i])){
                cnt++;
            }
        }
        mx=max(mx,cnt);
        int low=0,hi=k;
        while(hi<s.length()){
            if(isVowel(s[low])){
                cnt--;
            }
            if(isVowel(s[hi])){
                cnt++;
            }
            mx=max(mx,cnt);
            low++,hi++;
        }
        return mx;
    }
};