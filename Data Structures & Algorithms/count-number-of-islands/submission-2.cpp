class Solution
{
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    ans++;
                    vis[i][j] = true;
                    q.push({i, j});

                    while (!q.empty())
                    {
                        auto [x, y] = q.front();
                        q.pop();

                        for (auto &d : dir)
                        {
                            int nx = x + d[0];
                            int ny = y + d[1];

                            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                                grid[nx][ny] == '1' && !vis[nx][ny])
                            {

                                vis[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};