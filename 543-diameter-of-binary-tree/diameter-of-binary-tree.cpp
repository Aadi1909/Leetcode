class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int answer = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if (node == nullptr) return 0;
            int l = dfs(node->left);
            int r = dfs(node->right);
            answer = max(answer, l + r);
            return max(l, r) + 1;
        };
        dfs(root);
        return answer;
    }
};