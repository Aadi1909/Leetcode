class Solution {
public:
    int mySqrt(int x) {
        
        int left = 0;
        int right = x;
        
        long long validAns = 0;
        
        while(left <= right){
            long long mid = left + (right - left)/2;
            long long int root = mid * mid;
            
        
            if(root <= x){
                validAns = mid;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
            
        }
        return validAns;
    }
};
