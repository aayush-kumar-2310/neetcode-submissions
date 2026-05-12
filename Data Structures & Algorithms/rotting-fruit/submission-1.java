class Solution {

    private boolean isValid(int x, int y, int[][] grid){
        if(x < 0 || x >= grid.length)
            return false;
        if(y < 0 || y >= grid[0].length)
            return false;
        if(grid[x][y] != 1)
            return false;
        
        return true;
    }

    int[][] dir = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };

    public int orangesRotting(int[][] grid) {
        Queue<int[]> q = new LinkedList<>();
        int fresh = 0;
        int ans=0;
        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[0].length; j++){
                if(grid[i][j] == 2)
                    q.offer(new int[]{i,j});
                if(grid[i][j] == 1)
                    fresh++;
            }
        }

        if(fresh == 0)
            return 0;

        while(!q.isEmpty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                int [] node = q.poll();
                int x = node[0], y = node[1];

                for(int[] d: dir){
                    int nx = x+d[0];
                    int ny = y+d[1];

                    if(isValid(nx, ny, grid)){
                        fresh--;
                        q.offer(new int[]{nx, ny});
                        grid[nx][ny] = 2;
                    }
                }
            }
            ans++;
        }

        return fresh == 0?ans-1:-1;
    }
}
