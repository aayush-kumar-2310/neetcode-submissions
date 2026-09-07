class Solution {
public:

    bool dfs(int node, vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &currVis, stack<int> &ans){
        if(currVis[node])
            return false;
        if(vis[node])
            return true;

        currVis[node] = true;
        vis[node] = true;

        for(int i: graph[node]){
            if(!dfs(i, graph, vis, currVis, ans)){
                return false;
            }
        }

        ans.push(node);
        currVis[node] = false;
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);
        vector<bool> currVis(numCourses, false);
        stack<int> st;
        vector<vector<int>> graph(numCourses, vector<int>());

        for(auto it: prerequisites){
            graph[it[0]].push_back(it[1]);
        }

        for(int i=0; i<numCourses; i++){
            if(!dfs(i, graph, vis, currVis, st)){
                return {};
            }
        }

        vector<int> ans;
        while(!st.empty()){
            int tmp = st.top();
            ans.push_back(tmp);
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
