class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool uf[26] = {};
        int check[26] = {0};
        for(int i = 0; i < (int)word.length(); i++){
            if(word[i] >= 65 && word[i] <= 90){
                if(check[word[i] -'A'] != -1) {
                    if(uf[word[i] - 'A'] > 0)check[word[i] - 'A'] = 1;
                    else {
                        check[word[i] - 'A'] = -1;
                    }
                }
            }
            else{
                uf[word[i] - 'a'] = true;
                if(check[word[i] - 'a'] == 1)check[word[i] - 'a'] = -1;
            }
        }
        int count = 0;
        for(int i = 0; i < 26; i++){
            count += check[i] == 1 ? 1 : 0;
        }
        return count;
    }
};