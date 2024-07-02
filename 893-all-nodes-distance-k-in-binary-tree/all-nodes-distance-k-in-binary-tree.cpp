class Solution {
public:

    void generateParent(TreeNode* root, map<TreeNode*, TreeNode*>& mp){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; ++i){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr){
                    q.push(node->left);
                    mp[node->left] = node;
                }
                if(node->right != nullptr){
                    q.push(node->right);
                    mp[node->right] = node;
                }
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> answer;
        map<TreeNode*, TreeNode*> parent;
        generateParent(root, parent);
        set<TreeNode*> st;
        queue<TreeNode*> q;
        st.insert(target);
        q.push(target);
        while(k--  and !q.empty()){
            int size = q.size();
            for(int i = 0; i < size; ++i){
                TreeNode* node = q.front(); q.pop();
                if(node->left != nullptr and st.find(node->left) == st.end()){
                    q.push(node->left);
                    st.insert(node->left);
                }
                if(node->right != nullptr and st.find(node->right) == st.end()){
                    q.push(node->right);
                    st.insert(node->right);
                }
                if(parent.find(node) != parent.end() && st.find(parent[node]) == st.end()){
                    q.push(parent[node]);
                    st.insert(parent[node]);
               }
            }
        }
        while(!q.empty()){
            answer.push_back(q.front()->val);
            q.pop();
        }
        return answer;
    }
};