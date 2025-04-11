class Solution {
public:
  int minOperations(vector<int>& nums, int k) {
    map<int, int> mp;
    for (int &num : nums) {
      mp[num]++;
    }
    int unequal = 0;
    for (auto& m : mp) {
      if (m.first < k) return -1;
      unequal += m.first != k ? 1 : 0;
    }
    return unequal;
  }
};