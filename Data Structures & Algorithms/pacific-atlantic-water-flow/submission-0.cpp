class Solution {
   public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool isValid(int x, int y, int m, int n) {
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return false;
        }

        return true;
    }

    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        if (vis[x][y]) return;

        vis[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int newX = x + dir[i][0];
            int newY = y + dir[i][1];

            if (isValid(newX, newY, grid.size(), grid[0].size()) &&
                grid[newX][newY] >= grid[x][y]) {
                dfs(newX, newY, grid, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis1(m, vector<bool>(n, false));
        vector<vector<bool>> vis2(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(i, 0, grid, vis1);
        }

        for (int i = 0; i < n; i++) {
            dfs(0, i, grid, vis1);
        }

        for (int i = 0; i < m; i++) {
            dfs(i, n - 1, grid, vis2);
        }

        for (int i = 0; i < n; i++) {
            dfs(m - 1, i, grid, vis2);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis1[i][j] && vis2[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};