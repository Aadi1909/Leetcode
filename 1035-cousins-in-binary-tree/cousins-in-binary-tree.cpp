class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> val;
            int sz = q.size();
            for(int i = 0; i < sz; ++i){
                TreeNode* node = q.front(); q.pop();
                if (node->left != nullptr && node->right != nullptr) {
                    if ((node->left->val == x && node->right->val == y) ||
                        (node->left->val == y && node->right->val == x)) {
                        return false;
                    }
                }
                if(node->left != nullptr){
                    if(node->left->val == x) val.push_back(node->val);
                    else if(node->left->val == y) val.push_back(node->val);
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    if(node->right->val == x) val.push_back(node->val);
                    else if(node->right->val == y) val.push_back(node->val);
                    q.push(node->right);
                }
            }
            if(val.size() == 2){
                if(val[1] != val[0]) return true;
            }
            else if(val.size() == 1){
                return false;
            }
        }
        return false;
    }
};