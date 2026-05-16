class Solution {
public:
    int solve(int idx, vector<int>& dp, vector<int>& cost){
        if(idx == 0 || idx == 1)
            return 0;

        if(dp[idx] != INT_MAX)
            return dp[idx];

        int a = cost[idx-1] + solve(idx-1, dp, cost);
        int b = cost[idx-2] + solve(idx-2, dp, cost);

        return dp[idx] = min(a,b);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, INT_MAX);
        solve(cost.size(), dp, cost);
        return dp[cost.size()];
    }
};
