
/*

Battleships in a Board

Given an 2D board, count how many different battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:

You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example:
X..X
...X
...X
In the above board there are 2 battleships.
Invalid Example:
...X
XXXX
...X
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.

*/
//Solution 1: Typical Graph solution. 

    vector<int> directions={0, -1, 0, 1, 0 };
    void DFS( vector<vector<char>>& board, int m , int n, int i, int j ){
        board[i][j] = '.';
        for ( int k=0 ; k < directions.size() -1 ; k++ ){
            int new_i = i + directions[k];
            int new_j = j + directions[k+1] ;
            
            if ( new_i < 0  || new_j < 0   ||
                 new_i >= m || new_j >= n  ||
                 board[new_i][new_j] == '.' )  continue;
                 DFS( board, m, n , new_i, new_j );
        }
    }


    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        if ( m == 0 ) return 0;
        int n = board[0].size();
        int count=0;
        
        for ( int row =0; row < m  ; ++row){
            for ( int col =0 ; col < n ; ++col) { 
                if ( board[row][col] == 'X' ){ 
                    count++;
                    DFS( board, m, n , row, col );
                }
            }
        }
        return count;
    }

//	Solution 2: O(n) and o(1) space. ( Inspired from a different solutions ) 
	
	public int countBattleships(char[][] board) {
        int m = board.length;
        if (m==0) return 0;
        int n = board[0].length;
        
        int count=0;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == '.') continue;
                if (i > 0 && board[i-1][j] == 'X') continue;
                if (j > 0 && board[i][j-1] == 'X') continue;
                count++;
            }
        }
        
        return count;
    }