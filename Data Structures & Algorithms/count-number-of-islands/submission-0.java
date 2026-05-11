class Solution {

    private boolean isValid(int x, int y, int a, int b, char[][] grid, boolean[][] visited){
        if(x<0 || x>=a)
            return false;
        if(y<0 || y>=b)
            return false;

        if(grid[x][y] == '0' || visited[x][y])
            return false;
        
        return true;
    }

    private void solve(char[][] grid, boolean[][] visited, int x, int y){
        if(!isValid(x, y, grid.length, grid[0].length, grid, visited))
            return;

        visited[x][y] = true;

        solve(grid, visited, x+1, y);
        solve(grid, visited, x-1, y);
        solve(grid, visited, x, y+1);
        solve(grid, visited, x, y-1);
    }

    public int numIslands(char[][] grid) {
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        int ans = 0;

        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[0].length; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    ans++;
                    solve(grid, visited, i, j);
                }
            }
        }

        return ans;
    }
}
