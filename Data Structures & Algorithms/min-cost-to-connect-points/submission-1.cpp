class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        if (points.size() == 1) return 0;

        int ans = 0;

        vector<bool> vis(points.size(), false);

        pq.push({0, 0});

        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            int idx = node.second;
            if (vis[idx]) continue;
            vis[idx] = true;

            ans += node.first;

            for (int i = 0; i < points.size(); i++) {
                if (i == idx || vis[i]) continue;
                pq.push({abs(points[idx][0] - points[i][0]) + abs(points[idx][1] - points[i][1]),i});
            }
        }
        return ans;
    }
};
