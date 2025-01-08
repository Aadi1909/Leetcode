class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        stack<pair<TreeNode*, pair<int64_t, unordered_map<int64_t, int64_t>>>> s;
        unordered_map<int64_t, int64_t> initialPrefixSumCount;
        initialPrefixSumCount[0] = 1;
        s.push({root, {root->val, initialPrefixSumCount}});
        int count = 0;
        while (!s.empty()) {
            auto [node, state] = s.top();
            s.pop();
            auto [currentSum, prefixSumCount] = state;
            count += prefixSumCount[currentSum - targetSum];
            prefixSumCount[currentSum]++;
            if (node->right) {
                s.push({node->right, {1LL * currentSum + node->right->val, prefixSumCount}});
            }
            if (node->left) {
                s.push({node->left, {1LL * currentSum + node->left->val, prefixSumCount}});
            }
        }
        return count;
    }
};
