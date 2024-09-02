class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0){
            return 1;
        }
        vector<int> bits;
        while(n){
            if(n & 1) bits.push_back(0);
            else bits.push_back(1);
            n >>= 1;
        }
        int power = 0;
        int two = 0;
        for(int i = (int) bits.size() - 1; i >= 0; --i){
            if(bits[i]) power = power + pow(2, i);
            two++; 
        }
        return power;
    }
};