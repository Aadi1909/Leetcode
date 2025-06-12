class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> seen;
        unordered_set<pair<int, int>, pair_hash> uniquePairs;

        for (int num : nums) {
            if (seen.count(num - k)) {
                uniquePairs.insert({min(num, num - k), max(num, num - k)});
            }
            if (seen.count(num + k)) {
                uniquePairs.insert({min(num, num + k), max(num, num + k)});
            }
            seen.insert(num);
        }

        return uniquePairs.size();
    }
};
