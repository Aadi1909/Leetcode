class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int sum = 0;
        for(int i = 0; i < derived.size(); ++i){
           sum = sum ^ derived[i]; 
        }
        
        return !sum;
    }
};