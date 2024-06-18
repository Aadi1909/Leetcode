class Solution {
public:
    vector<string> T = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;

    void solve(int low, string &s, string &str){
        if(str.length() == s.length()){
            res.push_back(str);
            return;
        }
        for(int j = low; j < s.length(); ++j){
            int idx = s[j] - '0';
            for(int i = 0; i < T[idx].length(); ++i){
                str += T[idx][i];
                solve(j + 1, s, str);
                str.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        string str = "";
        if(digits == ""){
            return {};
        }
        solve(0, digits, str);
        return res;
    }
};