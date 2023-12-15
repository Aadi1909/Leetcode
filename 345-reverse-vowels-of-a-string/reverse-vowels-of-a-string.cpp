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
        int first = -1, last = -1;
        for(int i = s.length()-1; i >= 0; i--){
            if(isVowel(s[i])){
                last = i;
                break;
            }
        }
        for(int i = 0; i < s.length(); i++){
            if(isVowel(s[i])){
                first = i;
                break;
            }
        }
        if(first == -1 && last == -1){
            return s;
        }
        int low = first, hi = last;
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