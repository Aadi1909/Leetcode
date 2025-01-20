class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<int, char>> stk;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] >= 97 && s[i] <= 122) continue;
            if(!stk.empty() && s[i] == ')' && stk.top().second == '('){
                stk.pop();
            }
            else{
                stk.push({i, s[i]});
            }
        }
        while(!stk.empty()){
            s[stk.top().first] = '0';
            stk.pop();
        }
        string answer = "";
        for(int i = 0; i < s.length(); ++i){
            if(s[i] != '0'){
                answer += s[i];
            }
        }
        return answer;
    }
};