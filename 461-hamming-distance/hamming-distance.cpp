class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = 0;
        while(x > 0 || y > 0){
            int b = (x & 1), c = (y & 1);
            if(b + c == 1){
                diff++;
            }
            x >>= 1, y >>= 1; 
        }
        return diff;
    }
};