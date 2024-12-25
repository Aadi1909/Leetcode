class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> answer;
        answer.push_back(root->val);
        while (!q.empty()) {
            int sz = q.size();
            priority_queue<int> pq;
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front(); q.pop();
                if (node->left) { 
                    q.push(node->left);
                    pq.push(node->left->val);
                }
                if (node->right) { 
                    q.push(node->right); 
                    pq.push(node->right->val);
                }
            }
            if (pq.size() > 0) answer.push_back(pq.top());
        }
        return answer;
    }
};