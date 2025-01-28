class Solution {
public:
    int maxDepth(TreeNode* root) {
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if (node == nullptr) return 0;
            return max(dfs(node->left), dfs(node->right)) + 1; 
        };     
        return dfs(root);
    }
};