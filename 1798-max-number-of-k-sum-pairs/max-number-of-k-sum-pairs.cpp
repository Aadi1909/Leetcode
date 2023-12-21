class Solution {
public:
    int maxOperations(std::vector<int>& nums, int k) {
        unordered_map<int, int> numCounts;
        int operationCount = 0;
        for (int num : nums) {
            if (numCounts.find(k - num) != numCounts.end() && numCounts[k - num] > 0) {
                operationCount++;
                numCounts[k - num]--;
            } else {
                if (numCounts.find(num) == numCounts.end())
                    numCounts[num] = 0;
                numCounts[num]++;
            }
        }

        return operationCount;
    }
};