class Solution {
public:
    bool isVowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' 
         || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    string reverseVowels(string s) {
        if(s.length() == 1){
            return s;
        }
        int low = 0, hi = s.length()-1;
        while(low <= hi){
            if(isVowel(s[low]) && isVowel(s[hi])){
                swap(s[low], s[hi]);
                low++, hi--;
            }
            else if(isVowel(s[low]) && !isVowel(s[hi])) hi--;
            else low++;
        }
        return s;
    }
};