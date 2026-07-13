class Solution {
   public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool isValid(int i, int j, int m, int n) {
        if (i < 0 || i >= m) return false;
        if (j < 0 || j >= n) return false;
        return true;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        int ans = 0;
        int tmp = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isValid(i, j, m, n) && grid[i][j] == 1 && !vis[i][j]) {
                    q.push({i, j});
                    vis[i][j] = true;

                    while (!q.empty()) {
                        tmp += 1;
                        pair<int, int> coord = q.front();
                        int x = coord.first;
                        int y = coord.second;
                        q.pop();

                        for (auto it : dir) {
                            int nx = x + it[0];
                            int ny = y + it[1];

                            if (isValid(nx, ny, m, n) && !vis[nx][ny] && grid[nx][ny] == 1) {
                                vis[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                    ans = max(ans, tmp);
                    tmp = 0;
                }
            }
        }
        return ans;
    }
};