class Solution {
public:
    int maxUniqueSplit(string s) {
        set<string> st;
        int answer = 0;
        function<void(int)> sol = [&](int i) {
            if (i >= s.length()) {
                answer = max(answer, (int)st.size());
                return;
            }
            for (int j = i; j < s.length(); ++j) {
                string sub = s.substr(i, j - i + 1); 
                if (st.find(sub) == st.end()) {
                    st.insert(sub);
                    sol(j + 1);
                    st.erase(sub); 
                }
            }
        };
        sol(0);
        return answer;
    }
};
