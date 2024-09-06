class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int val = mean * (n + (int) rolls.size()) - sum;
        if(val > n * 6 || val <= 0 || val / n < 1){
            return {};
        }
        int factor = val / n;
        vector<int> ans;
        for(int i = 0; i < n; ++i){
            ans.push_back(factor);
            val -= factor;
        }

        for(int i : ans)cout << i << ' ';
        cout << '\n';


        if(val > 0){
            for(int i = 0; i < ans.size(); ++i){
                int r = 6 - ans[i];
                if(val >= r){
                    ans[i] += r;
                    val -= r;
                }
                else {
                    ans[i] += val;
                    val = 0;
                }
                if(val == 0) break;
            }
        }
        return ans;
    }
};