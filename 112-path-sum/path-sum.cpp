class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        function<bool(TreeNode*, int)> dfs = [&](TreeNode* node, int sum) -> bool {
            if (node == nullptr) {
                return false;
            }
            sum += node->val;
            if (node->left == nullptr && node->right == nullptr) {
                return sum == targetSum;
            }
            return dfs(node->left, sum) || dfs(node->right, sum);
        };
        return dfs(root, 0);
    }
};