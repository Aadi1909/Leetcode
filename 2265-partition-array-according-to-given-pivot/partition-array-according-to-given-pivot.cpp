class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> a_s(nums.size(), 0);
        int l_o = 0, h_i = nums.size() - 1;
        for (int i = 0, j = nums.size() - 1; i < nums.size(); ++i, --j) {
            if (nums[i] < pivot) {
                a_s[l_o] = nums[i];
                l_o++;
            }
            if (nums[j] > pivot) {
                a_s[h_i] = nums[j];
                h_i--;
            }
        }
        while (l_o <= h_i) {
            a_s[l_o] = pivot;
            l_o++;
        }
        return a_s;
    }
};