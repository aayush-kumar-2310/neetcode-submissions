class Solution {
   public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid.empty()) return;

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) q.push({i, j});
            }
        }

        while (!q.empty()) {
            pair<int, int> top = q.front();
            int x = top.first;
            int y = top.second;
            q.pop();

            for (auto it : dir) {
                int nx = x + it[0];
                int ny = y + it[1];

                if (nx >= 0 && nx <= m - 1 && ny >= 0 && ny <= n - 1 && grid[nx][ny] != -1) {
                    if (grid[nx][ny] == 2147483647 || grid[nx][ny] > grid[x][y] + 1) {
                        grid[nx][ny] = grid[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return;
    }
};
