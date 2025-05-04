class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mp;
        for (auto domino : dominoes) {
            sort(domino.begin(), domino.end());
            mp[{domino[0], domino[1]}]++;
        }
        int equalDominoes = 0;
        for (auto& m : mp) {
            if (m.second > 1) equalDominoes += m.second * (m.second - 1) / 2;
        }

        return equalDominoes;
    }
};