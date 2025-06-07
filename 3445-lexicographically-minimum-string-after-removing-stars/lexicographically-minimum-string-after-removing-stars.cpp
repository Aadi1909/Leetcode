class Solution {
public:
    string clearStars(string s) {
        map<char, set<int>> mp;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '*') {
                if (!mp.empty()) {
                    auto it = mp.begin();
                    it->second.erase(*it->second.rbegin());
                    if (it->second.empty()) {
                        mp.erase(it);
                    }
                }
            }
            if (s[i] != '*') mp[s[i]].insert(i);
        }

        string answer = "";
        set<int> st;
        for (auto& m : mp) {
            set<int> sts = m.second;
            for (int stx : sts)
                st.insert(stx);
        }
        vector<int> index(st.begin(), st.end());
        for (int idx : index) {
            answer.push_back(s[idx]);
        }
        return answer;
    }
};
