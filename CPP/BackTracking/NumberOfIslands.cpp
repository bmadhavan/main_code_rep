Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3


My Solution: 
DFS. Start from any corner.If a co-ordinate is '1' then increment the island count and do DFS from that element. Set all reachable elements to 0. 
In DFS walk through all directions. check for 1 and valid conditions. 

class Solution {
    vector<int> direction = {0, -1, 0, 1, 0};
    void DFS( vector<vector<char>>& grid , int row , int col  ) {
        grid[row][col] = '0'; 
        
        for ( int i = 0; i<direction.size()-1 ; i++ ) { 
            int newrow = row + direction[i];
            int newcol = col + direction[i+1];
           
            if ( newrow < 0 || newcol < 0 || newrow >= grid.size() || 
                newcol >= grid[0].size() || grid[newrow][newcol] == '0')
                    continue;
            else
                DFS(grid, newrow, newcol);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int i, j;
        if ( grid.size() == 0 ) return 0; 
        int IslandCnt=0; 
        
        for ( i=0; i < grid.size(); i++ ){ 
            for ( j=0; j < grid[0].size(); j++ ) {
                if ( grid[i][j] == '1' ) {
                    IslandCnt++;
                    DFS(grid, i, j);
                }
            }
        }
        return IslandCnt++;
    }
}; 