class Solution {
public:
    int minCostClimbingStairs( vector<int>& cost ) {
        int n = cost.size();
        int dp[n + 1];
        memset(dp, -1, sizeof(dp));
        function < int ( int ) > costs = [ & ] ( int n ) {
            if ( n <= 1 ) {
                return 0;
            }
            if ( dp[n] != -1 ) return dp[ n ];
            int answer = costs( n - 1 ) + cost[ n - 1 ];
            if ( n - 2 >= 0 ) {
                answer = min(answer, costs( n - 2 ) + cost[ n - 2 ]);
            }
            dp[ n ] = answer;
            return dp[ n ];
        };
        return costs(n);
    }
};