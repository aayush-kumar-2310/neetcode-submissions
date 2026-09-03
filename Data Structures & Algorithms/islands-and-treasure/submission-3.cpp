class Solution {
   public:
    bool isValid(int x, int y, int m, int n, vector<vector<int>>& grid) {
        if (x < 0 || x >= m || y < 0 || y >= n)
            return false;
        else if (grid[x][y] == -1 || grid[x][y] == 0)
            return false;

        return true;
    }

    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();

            int oldX = top.first;
            int oldY = top.second;

            for (int i = 0; i < 4; i++) {
                int newX = oldX + dir[i][0];
                int newY = oldY + dir[i][1];

                if (isValid(newX, newY, m, n, grid) && grid[oldX][oldY] + 1 < grid[newX][newY]) {
                    grid[newX][newY] = grid[oldX][oldY] + 1;
                    q.push({newX, newY});
                }
            }
        }
    }
};
