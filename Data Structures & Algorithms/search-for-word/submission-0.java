class Solution {

    private boolean isValid(int x, int y, int a, int b, boolean[][] vis) {
        if (x >= a || x < 0)
            return false;

        if (y >= b || y < 0)
            return false;

        if (vis[x][y])
            return false;

        return true;
    }

    private boolean solve(boolean[][] visited, char[][] board,
                          StringBuilder tmp, String word,
                          int x, int y) {

        if (!isValid(x, y, board.length, board[0].length, visited))
            return false;

        tmp.append(board[x][y]);

        if (!word.startsWith(tmp.toString())) {
            tmp.deleteCharAt(tmp.length() - 1);
            return false;
        }

        if (word.contentEquals(tmp)) {
            return true;
        }

        visited[x][y] = true;

        boolean ans =
                solve(visited, board, tmp, word, x + 1, y) ||
                solve(visited, board, tmp, word, x - 1, y) ||
                solve(visited, board, tmp, word, x, y + 1) ||
                solve(visited, board, tmp, word, x, y - 1);

        visited[x][y] = false;
        tmp.deleteCharAt(tmp.length() - 1);
        return ans;
    }

    public boolean exist(char[][] board, String word) {

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {

                boolean[][] visited =
                        new boolean[board.length][board[0].length];
                StringBuilder tmp = new StringBuilder();
                if (solve(visited, board, tmp, word, i, j))
                    return true;
            }
        }
        return false;
    }
}