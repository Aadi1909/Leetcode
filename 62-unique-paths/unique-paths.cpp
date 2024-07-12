class Solution {
public:
    int uniquePaths ( int m , int n ) {
        int dp [ m ] [ n ];
        memset ( dp , -1, sizeof ( dp ) ); 
        // function< int ( int , int ) > sol = [ & ] ( int i , int j ) {
        //     if ( j >= n || i >= m ) return 0;
        //     if ( i == m-1 && j == n - 1 ) return 1;
        //     if ( dp [ i ] [ j ] != -1 ) return dp [ i ] [ j ] ;
        //     int left = sol ( i + 1, j );
        //     int right = sol ( i, j + 1 );
        //     return dp [ i ] [ j ] = left + right;
        // };
        // return sol ( 0 , 0 ); 

        dp [ 0 ] [ 0 ] = 1 ;
        for ( int i = 0; i < n; ++i ) dp [ 0 ] [ i ] = 1;
        for ( int j = 0; j < m; ++j ) dp [ j ] [ 0 ] = 1;

        for ( int i = 1; i < m; ++i ) {
            for ( int j = 1; j < n; ++j ) {
                dp [ i ] [ j ] = dp [ i - 1] [ j ] + dp [ i ] [ j - 1 ]; 
            }
        } 
        return dp [ m - 1 ] [ n - 1 ];
    }
};