class Solution {
public:
    
    bool checkPowersOfThree(int n) {
        vector<int> three;
        int val = 1;
        for (int i = 0; i <= 15; ++i) {
            three.push_back(val);
            val *=  3;
        }  
        function<bool(int64_t, int)> sol = [&](int64_t need, int idx) {
            if (need == n) return true;
            if (need > n || idx >= three.size()) return false;
            return (sol(need + three[idx] * 1LL, idx + 1) || sol(need, idx + 1));
        };
        return sol(0, 0);
    }
};

