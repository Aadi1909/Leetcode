class Solution {
public:
    int func ( int i , int n , int dp [] , vector <int> & nums ) {
        if ( i >= n ) return 0;
        int answer = 0;
        if ( dp [ i ] != -1 ) return dp [ i ];
        answer = max ( answer, nums [ i ] + func ( i + 2 , n , dp , nums ) ) ;
        answer = max ( answer, func ( i + 1 , n , dp , nums ) ) ;
        return dp [ i ] = answer ;
    }
    int rob ( vector <int> & nums ) {
        int n = nums.size ();
        int dp [ n + 2 ];
        memset ( dp , -1 , sizeof ( dp ) );
        return func ( 0 , n , dp , nums );
    }
};