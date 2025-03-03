class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> bits(n);
        for(int j = 0; j < n; ++j) {
            for(int i = 0; i <= 31; ++i) {
                if (nums[j] & (1 << i)) 
                    bits[j].push_back(i);
            }
        }
        int max_length = 1;
        set<int> st(bits[0].begin(), bits[0].end()); 
        int l_o = 0;
        for(int i = 1; i < n; ++i) {
            vector<int> new_bits = bits[i];
            bool is_valid = true;
            for (int new_bit : new_bits) {
                if (st.find(new_bit) != st.end()) {
                    is_valid = false;
                    break;
                }
            }
            while (!is_valid) {
                for (int rm : bits[l_o]) 
                    st.erase(rm);
                    l_o++;
                    is_valid = true;
                    for (int new_bit : new_bits) {
                        if (st.find(new_bit) != st.end()) {
                            is_valid = false;
                            break;
                        }
                }
            }
            for (int new_bit : new_bits) 
                st.insert(new_bit);
            max_length = max(max_length, i - l_o + 1);
        }

        return max_length;
    }
};
