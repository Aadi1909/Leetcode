class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long answer = 0;
        long long low = 0, hi = 1e14;
        while(low + 1 < hi){
            long long mid = low + (hi - low) / 2;
            long long count = 0;
            for(int i = 0; i < candies.size(); ++i){
                count += candies[i] / mid;
            }
            if(count >= k){
                answer = max<long long>(answer, mid);
                low = mid;
            }
            else{
                hi = mid;
            }
        }
        return answer;
    }
};