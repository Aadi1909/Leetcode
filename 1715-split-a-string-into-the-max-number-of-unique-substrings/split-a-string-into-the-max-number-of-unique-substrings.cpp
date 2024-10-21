class Solution {
public:
    int maxUniqueSplit(string s) {
        set<string> st;
        vector<string> v;
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
                    v.push_back(sub);
                    sol(j + 1);
                    st.erase(sub); 
                    v.pop_back();
                }
            }
        };
        sol(0);
        return answer;
    }
};
