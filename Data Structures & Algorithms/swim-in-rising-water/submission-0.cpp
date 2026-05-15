class Solution {
   public:
    bool isValid(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || x >= grid.size()) return false;
        if (y < 0 || y >= grid[0].size()) return false;
        if (grid[x][y] == -1) return false;
        return true;
    }

    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        
        pq.push({grid[0][0], {0, 0}});
        grid[0][0] = -1;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int weight = node.first;
            int x = node.second.first;
            int y = node.second.second;

            if(x == grid.size()-1 && y == grid[0].size()-1)
                return weight;

            for (auto it : dir) {
                int nx = x + it[0];
                int ny = y + it[1];

                if (isValid(nx, ny, grid)) {
                    pq.push({max(weight, grid[nx][ny]), {nx, ny}});
                    grid[nx][ny] = -1;
                }
            }
        }
    }
};
