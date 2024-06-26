class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        queue<TreeNode*> q;
        if (root != nullptr) {
            q.push(root);
        }   
        while (!q.empty()) {
            int sz = q.size();
            //if (q.front() != nullptr) answer.push_back(q.front()->val);
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front(); q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
                if (i == sz-1) {
                    answer.push_back(node->val);
                }
            }
        }
        return answer;
    }
};