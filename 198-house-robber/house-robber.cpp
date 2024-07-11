class Solution {
public:
    int rob ( vector <int> & nums ) {
        int n = nums.size ();
        int dp [ n + 2 ];
        for ( int i = 0; i <= n; ++i ) dp [ i ] = -1e9;
        dp [ n ] = dp [ n + 1 ] = 0;
        for ( int i = n - 1; i >= 0; i-- ) {
            dp [ i ] = max ( dp [ i ] , dp [ i + 1 ] );
            dp [ i ] = max ( dp [ i ] , dp [ i + 2 ] + nums [ i ] ) ;
        } 
        return dp [ 0 ];
    }
};