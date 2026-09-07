class Solution {
public:

    bool dfs(int node, vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &currVis){

        if(currVis[node])
            return false;

        if(vis[node])
            return true;
            
        vis[node] = true;
        currVis[node] = true;

        for(int i: graph[node]){
            if(!dfs(i, graph, vis, currVis))
                return false;            
        }

        currVis[node] = false;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);
        vector<bool> currVis(numCourses, false);

        vector<vector<int>> graph(numCourses, vector<int>());
        
        for(auto it: prerequisites)
            graph[it[0]].push_back(it[1]);
    
        for(int i=0; i<numCourses; i++){
            if(!dfs(i, graph, vis, currVis))
                return false;
        }
    
        return true;
    }

};
