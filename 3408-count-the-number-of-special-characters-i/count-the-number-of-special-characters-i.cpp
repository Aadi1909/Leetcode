class Solution {
public:
    int numberOfSpecialChars(string word) {
        int f1[26] = {}, f2[26] = {};
        for(int i = 0; i < (int)word.length(); i++){
            if(word[i] >= 65 && word[i] <= 90){
                f1[word[i] - 'A']++;
            }
            else{
                f2[word[i] - 'a']++;
            }
        } 
        int count = 0;
        for(int i = 0; i < 26; i++){
            count += f1[i] > 0 && f2[i] > 0 ? 1 : 0;
        }
        return count;
    }
};