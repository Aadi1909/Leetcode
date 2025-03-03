class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int a_s = nums.size();
        int l_o = 0;
        bool ok = false;
        int s_m = 0, i = 0;
        for(i = 0; i < nums.size(); ++i) {
            s_m += nums[i];
            while (l_o < i && s_m >= target) {
                a_s = min(a_s, i - l_o + 1);
                s_m -= nums[l_o];
                l_o++;
                ok = true;
            }
            if (s_m >= target) a_s = min(a_s, i - l_o + 1);
        }
        if (s_m >= target) {
            a_s = min(a_s, i - l_o + 1);
            ok = true;
        }
        if(!ok) return 0;
        return a_s;
    }
};