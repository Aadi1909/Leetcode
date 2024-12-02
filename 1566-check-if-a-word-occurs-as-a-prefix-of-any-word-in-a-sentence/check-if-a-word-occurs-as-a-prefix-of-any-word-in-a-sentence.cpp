class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        map<int, string> mp;
        vector<string> st;
        string word;
        stringstream ss(sentence);
        while(getline(ss, word, ' ')){
            st.push_back(word);
        }
        for (int i = 0; i < st.size(); ++i) {
            mp[i] = st[i];
        }
        for (auto& m : mp) {
            string s = m.second;
            int count = 0, j = 0;
            while (s[j] == searchWord[j] && j < min(s.length(), searchWord.length())) count++, j++;
            if (count == searchWord.length()) return m.first + 1;
        }
        return -1;
    }
};