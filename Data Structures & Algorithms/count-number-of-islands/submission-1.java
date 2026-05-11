class Solution {

    private boolean isValid(int x, int y, int a, int b, char[][] grid){
        if(x<0 || x>=a)
            return false;
        if(y<0 || y>=b)
            return false;

        if(grid[x][y] != '1')
            return false;
        
        return true;
    }

    private void solve(char[][] grid, int x, int y){
        if(!isValid(x, y, grid.length, grid[0].length, grid))
            return;

        grid[x][y]++;

        solve(grid, x+1, y);
        solve(grid, x-1, y);
        solve(grid, x, y+1);
        solve(grid, x, y-1);
    }

    public int numIslands(char[][] grid) {
        int ans = 0;

        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[0].length; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    solve(grid, i, j);
                }
            }
        }

        return ans;
    }
}
