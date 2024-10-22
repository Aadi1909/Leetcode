class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        long long answer = -1e9;
        int level = 0, currlevel = 1;
        while(!q.empty()){
            long long sum = 0;
            int sz = q.size();
            for(int  i = 0; i < sz; ++i){
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            if(sum > answer){
                level = currlevel;
                answer = sum;
            }
            currlevel += 1;
        }
        return level;
    }
};