class Solution {

    int[][] dir = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };

    private boolean isValid(int x, int y, char[][] board){
        if(x<0 || x >= board.length)
            return false;
        if(y<0 || y >= board[0].length)
            return false;
        if(board[x][y] != 'O')
            return false;
        
        return true;
    }

    public void solve(char[][] board) {
        Queue<int[]> q = new LinkedList<>();

        for(int i=0; i<board[0].length; i++){
            if(board[0][i] == 'O')
                q.offer(new int[]{0,i});
            if(board[board.length-1][i] == 'O')
                q.offer(new int[]{board.length-1, i});
        }

        for(int i=0; i<board.length; i++){
            if(board[i][0] == 'O')
                q.offer(new int[]{i,0});
            if(board[i][board[0].length-1] == 'O')
                q.offer(new int[]{i, board[0].length-1});
        }

        while(!q.isEmpty()){
            int[] node = q.poll();
            int x = node[0], y = node[1];
            board[x][y] = '#';
            for(int[] d: dir){
                int nx = x+d[0], ny = y+d[1];
                if(isValid(nx, ny, board)){
                    
                    q.offer(new int[]{nx, ny});
                }
            }
        }

        for(int i=0; i<board.length; i++){
            for(int j=0; j<board[0].length; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
}
