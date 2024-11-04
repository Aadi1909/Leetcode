class Solution {
public:
    void compress(string &answer, int &count, int i, string &word) {
        if (count > 9) {
            while (count) {
                if (count > 9) {
                    answer += '9';
                    answer += word[i];
                }
                else {
                    answer += count + '0';
                    answer += word[i];
                }
                if (count < 9) break;
                else count -= 9;
            }
        }
        else {
            answer += count + '0';
            answer += word[i];
        }
    }
    string compressedString(string word) {
        string answer = "";
        int count = 1;
        for (int i = 1; i < word.length(); ++i) {
            if (word[i] != word[i - 1]){
                compress(answer, count, i - 1, word);
                count = 0;
            }
            count += 1;
        }
        if (count > 0) {
            compress(answer, count, word.length() - 1, word);
        }
        return answer;
    }
};