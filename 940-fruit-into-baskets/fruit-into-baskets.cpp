class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m_p;
        int a_s = 0;
        int l_o = 0;
        int c_t = 0;
        for (int i = 0; i < fruits.size(); ++i) {
            m_p[fruits[i]]++;
            c_t++;
            while (l_o < i && m_p.size() > 2) {
                m_p[fruits[l_o]]--;
                if (!m_p[fruits[l_o]]) m_p.erase(fruits[l_o]);
                l_o++;
                c_t--;
            }
            a_s = max(a_s, c_t);
        }
        a_s = max(a_s, c_t);
        return a_s;
    }
};