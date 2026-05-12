class Solution {

    private boolean isValid(int x, int y, int[][] grid){
        if(x<0 || x>= grid.length)
            return false;
        if(y<0 || y >= grid[0].length)
            return false;
        if(grid[x][y] == -1)
            return false;
        
        return true;
    }

    int[][] dir = {
        {-1, 0}, // up
        {1, 0},  // down
        {0, -1}, // left
        {0, 1}   // right
    };

    public void islandsAndTreasure(int[][] grid) {
        Queue<int[]> q = new LinkedList<>();

        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[0].length; j++){
                if(grid[i][j] == 0){
                    q.offer(new int[]{i,j});
                }
            }
        }

        while(!q.isEmpty()){
            int[] top = q.poll();
            int x = top[0], y = top[1];

            for(int[] d : dir){
                int nx = x + d[0];
                int ny = y + d[1];      

                if(isValid(nx, ny, grid) && grid[nx][ny] > grid[x][y]+1){
                    q.offer(new int[]{nx, ny});
                    grid[nx][ny] = grid[x][y]+1;
                }
            }
        }
    }
}
