class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bit = __builtin_popcount(num2);
        int answer = 0;
        for(int i = 32; i >= 0 && bit; --i){
            if(num1 & (1LL << i)) { answer |= (1LL << i), bit--; }
        }
        int i = 0;
        while(bit && i <= 32){
            if((num1 & (1LL << i)) == 0) { answer |= (1LL << i), bit--;}
            i++;
        }
        return answer;
    }
};