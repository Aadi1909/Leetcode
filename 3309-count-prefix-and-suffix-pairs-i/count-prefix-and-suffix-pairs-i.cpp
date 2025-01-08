class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int answer = 0;
        function<bool(string&, string&)> find = [&](string& a, string& b){
            if(a.length() > b.length()) return false;
            for(int i = 0; i < a.length(); ++i){
                if(a[i] != b[i]) return false;
            }
            int j = b.length() - 1;
            for(int i = a.length() - 1; i >= 0; --i){
                if(a[i] != b[j--]) return false;
            }
            return true;
        };
        for(int i = 0; i < words.size(); ++i){
            for(int j = i + 1; j < words.size(); ++j){
                if(find(words[i], words[j])) answer++;
            }
        }
        return answer;
    }
};