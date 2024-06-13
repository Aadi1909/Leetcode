class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        // int64_t answer = 0;
        int64_t low = 0, hi = 1e8;
        while(low + 1 < hi){
            int64_t mid = low + (hi - low) / 2;
            int64_t count = 0;
            for(int& c : candies){
                count += c / mid;
            }
            if(count >= k){
                //answer = max<int64_t>(answer, mid);
                low = mid;
            }
            else{
                hi = mid;
            }
        }
        return low;
    }
};