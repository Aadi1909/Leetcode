class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool ok = true;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if (node == nullptr) return 0;
            int r = dfs(node->right);
            int l = dfs(node->left);
            if (abs(r - l) > 1) ok = false;
            return max(l, r) + 1;
        };
        dfs(root);
        return ok;
    }
};