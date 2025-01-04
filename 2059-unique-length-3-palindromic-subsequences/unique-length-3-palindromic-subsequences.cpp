class Solution {
public:
    int countPalindromicSubsequence(std::string s) {
        std::vector<int> first(26, -1);
        std::vector<int> last(26, -1);
        for(int i = 0; i < s.length(); ++i){
            if(first[s[i]-'a'] == -1){
                first[s[i]-'a'] = i;
            }
            last[s[i]-'a'] = i;
        }
        int answer = 0;
        for(char i = 'a'; i <= 'z'; ++i){
            int x = first[i-'a'];
            int y = last[i-'a'];
            if(x != -1 && y - x > 1){
                std::unordered_set<char> uq(s.begin() + x + 1, s.begin() + y);
                answer += uq.size();
            }
        }
        return answer;
    }
};