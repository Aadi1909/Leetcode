class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> result(code.size(), 0);
        if(k == 0){
            return result;
        }
        else if(k > 0){
            for(int i = 0; i < code.size(); ++i){
                int j = i + 1;
                int round = k;
                while(round--){
                    result[i] += code[j%code.size()];
                    j++;
                }
            }
            return result;
        }
        else{
            int n = code.size();
            for (int i = 0; i < n; ++i) {
                for (int j = 1; j <= -k; ++j) {
                    result[i] += code[(i - j + n) % n];
                }
            }
        }
        return result;
    }
};