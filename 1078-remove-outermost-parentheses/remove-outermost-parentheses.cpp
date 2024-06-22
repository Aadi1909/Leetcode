class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string answer = "";
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '('){
                st.push(s[i]);
                if(st.size() > 1)answer += s[i];
            }
            else{
                if(st.size() == 1){
                    st.pop();
                }
                else{
                    answer += s[i];
                    if(st.top() == '('){
                        st.pop();
                    }
                }
            }
        }
        return answer;
    }
};