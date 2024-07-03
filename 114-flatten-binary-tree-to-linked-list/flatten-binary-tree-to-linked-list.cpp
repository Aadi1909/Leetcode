class Solution {
public:
    void solve(TreeNode* node, TreeNode* &prev){
        if(node == nullptr) return ;
        TreeNode* right = node->right;
        TreeNode* left = node->left;
        if(node != prev){
            prev->right = node;
            prev->left = nullptr;
            prev = node;
        }
        solve(left, prev);
        solve(right, prev);
    }
    void flatten(TreeNode* root) {
        solve(root, root);
    }
};