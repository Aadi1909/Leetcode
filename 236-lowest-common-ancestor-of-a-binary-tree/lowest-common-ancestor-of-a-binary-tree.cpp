class Solution {
public:
    TreeNode* f(TreeNode* node, int a, int b) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->val == a) return node;
        if (node->val == b) return node;
        TreeNode* l = f(node->left, a, b);
        TreeNode* r = f(node->right, a, b);
        if (l == nullptr) return r;
        if (r == nullptr) return l;
        return node;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root, p->val, q->val);
    }
};