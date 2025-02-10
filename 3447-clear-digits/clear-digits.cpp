class Solution {
public:
    string clearDigits(string s) {
        int n = (int)s.length();
        stack<char> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] >= 97 && s[i] <= 122) {
                st.push(s[i]);
            } else {
                if (!st.empty()) st.pop();
            }
        }
        string answer = "";
        while (!st.empty()) {
            answer += st.top();
            st.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};