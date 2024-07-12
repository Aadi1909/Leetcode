class Solution {
public:
    int uniquePaths ( int m , int n ) {
        int dp [ m ] [ n ];
        memset ( dp , -1, sizeof ( dp ) ); 
        function< int ( int , int ) > sol = [ & ] ( int i , int j ) {
            if ( i < 0 || j < 0 || j >= n || i >= m ) return 0;
            if ( i == m-1 && j == n - 1 ) return 1;
            if ( dp [ i ] [ j ] != -1 ) return dp [ i ] [ j ] ;
            int left = sol ( i + 1, j );
            int right = sol ( i, j + 1 );
            return dp [ i ] [ j ] = left + right;
        };
        return sol ( 0 , 0 ); 
    }
};