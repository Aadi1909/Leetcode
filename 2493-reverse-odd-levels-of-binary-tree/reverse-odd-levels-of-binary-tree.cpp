class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            queue<TreeNode*> qq = q;
            vector<int> values;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                    values.push_back(node->left->val);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                    values.push_back(node->right->val);
                }
            }
            if (level & 1) {
                for (int i = 0; i < size; ++i) {
                    TreeNode* node = qq.front(); qq.pop();
                    if (node->left != nullptr) {
                        node->left->val = values.back();
                        values.pop_back();
                    }
                    if (node->right != nullptr) {
                        node->right->val = values.back();
                        values.pop_back();
                    }
                }
            }
            level++;
        }
        return root;
    }
};