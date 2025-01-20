class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<int, char>> stk;
        set<int> st;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] >= 97 && s[i] <= 122) continue;
            if(!stk.empty() && s[i] == ')' && stk.top().second == '('){
                int index = stk.top().first;
                st.erase(index);
                stk.pop();
            }
            else{
                stk.push({i, s[i]});
                st.insert(i);
            }
        }
        string answer = "";
        for(int i = 0; i < s.length(); ++i){
            if(st.find(i) == st.end()){
                answer += s[i];
            }
        }
        return answer;
    }
};