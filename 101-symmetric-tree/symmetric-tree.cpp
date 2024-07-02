class Solution {
public:
    bool solve(TreeNode* node1, TreeNode* node2) {
        if(node1 == nullptr and node2 == nullptr){
            return true;
        }
        if(node1 == nullptr or node2 == nullptr) return false;
        if(node1->val != node2->val){
            return false;
        }
        return solve(node1->left, node2->right) and solve(node1->right, node2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root, root);
    }
};