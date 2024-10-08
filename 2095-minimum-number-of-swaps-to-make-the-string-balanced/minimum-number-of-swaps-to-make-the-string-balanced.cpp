class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        string new_s;
        st.push(s[0]);
        for(int i = 1; i < s.length(); ++i){
            if(!st.empty() && s[i] == ']' && st.top() == '[') st.pop();
            else st.push(s[i]);
        }
        while(!st.empty()){
            new_s.push_back(st.top());
            st.pop();
        }
        int r = new_s.length() / 2;
        int ans = r / 2 + r % 2;
        return ans;
    }
};