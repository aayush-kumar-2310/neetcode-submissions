class Solution {
public:

    int solve(int i, vector<int>& cost, vector<int>& dp){
        if(i < 0)
            return 0;

        if(dp[i] != INT_MIN)
            return dp[i];

        int a = cost[i] + solve(i-2, cost, dp);
        int b = solve(i-1, cost, dp);

        return dp[i] = max(a,b);
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];

        vector<int> dp(nums.size(), INT_MIN);

        return solve(nums.size()-1, nums, dp);
    }
};
