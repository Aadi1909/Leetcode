
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;
        queue<TreeNode*> q;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long answer = 0;
        q.push(root);
        while (!q.empty()) {
            long long sum = 0;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* current = q.front();
                q.pop();
                sum += current->val;
                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }
            if (pq.size() < k) {
                pq.push(sum);
            } else if (pq.top() < sum) {
                pq.pop();
                pq.push(sum);
            }
        }
        if (pq.size() < k) return -1;
        return pq.top();
    }
};
