class Solution {
public:
    int uniquePathsWithObstacles ( vector < vector < int > > & Grid ) {
        int n = Grid.size ( );
        int m = Grid [ 0 ].size ( );
        int dp [ n ] [ m ];
        memset ( dp, -1, sizeof ( dp ) );
        function < int ( int, int ) > sol = [ & ] ( int i , int j ) {
            if ( Grid [ i ] [ j ] ) return 0;
            if ( i == n - 1 and j == m - 1 ) return 1;
            int answer = 0;
            if ( dp [ i ] [ j ] != -1 ) return dp [ i ] [ j ];
            if ( i + 1 < n ) answer += sol ( i + 1,  j ) ;
            if ( j + 1 < m ) answer += sol ( i , j + 1 );
            return dp [ i ] [ j ] = answer;
        };
        return sol ( 0 , 0 ) ;
    }
};