class Solution {
public:
    int answer = -1e9;
    int f(TreeNode* node){
        if(!node) return 0;
        int l = f(node->left);
        int r = f(node->right);
        l = max(0, l);
        r = max(0, r);
        answer = max(answer, l + r + node->val);
        return max(l, r) + node->val;
    }
    int maxPathSum(TreeNode* root) {
        int x = f(root);
        return answer;
    }
};