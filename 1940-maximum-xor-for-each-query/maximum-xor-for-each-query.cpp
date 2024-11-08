class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> answer;
        int XOR = 0;
        for(int i = 0; i < nums.size(); ++i){
            int num = 0;
            XOR = (XOR ^ nums[i]);
            for(int j = 0; i < 100000; ++j){
                if((1LL << j) >= (1LL << maximumBit)) break;  
                if(((1LL << j) & XOR) == 0){
                    num |= (1 << j);
                }
            }
            answer.push_back(num);
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};