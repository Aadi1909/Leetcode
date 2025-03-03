class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> a_s;
        for(int& num : nums) {
            if (num < pivot) {
                a_s.push_back(num);
            }
        }
        for (int &num : nums) {
            if (num == pivot) a_s.push_back(num);
        }
        for (int &num : nums) {
            if (num > pivot) a_s.push_back(num);
        }
        return a_s;
    }
};