class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        unordered_map< int, int > mp;
        long long currentSum = 0;
        for( int i = 0; i < k; ++i ) {
            mp[ nums[i] ]++;
            currentSum += nums[i];
        }
        if ( mp.size() == k ) maxSum = max( maxSum, currentSum ); 
        int lo = 0, hi = k;
        while ( hi < nums.size() ) {
            mp[ nums[lo] ]--;
            if ( mp[ nums[lo] ] == 0 ) mp.erase( nums[lo] );
            currentSum -= nums[lo];
            mp[ nums[hi] ]++;
            currentSum += nums[hi];
            if ( mp.size() == k ) maxSum = max( maxSum, currentSum );
            lo++, hi++;
        }
        return maxSum;
    }   
};