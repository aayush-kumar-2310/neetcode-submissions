class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        vector<vector<pair<int, int>>> adj(n);

        for(auto it: flights){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }

        vector<bool> vis(n, false);

        pq.push({0, {src, 0}});
        vis[src] = true;

        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
        
            int nd = node.second.first;
            int cost = node.first;
            int stops = node.second.second;

            if(nd == dst)
                return cost;

            vis[nd] = true;

            for(auto it: adj[nd]){
                if(!vis[it.first] && stops <= k){
                    pq.push({cost + it.second, {it.first, stops+1}});
                }
            }
        }

        return -1;
    }
};
