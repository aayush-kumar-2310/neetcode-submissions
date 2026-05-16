class Solution {
public:

    int solve(int i, int l, vector<int>& dp, vector<int>& nums){
        if(i<l)
            return 0;
        if(i == l)
            return nums[i];
        if(dp[i] != INT_MIN)
            return dp[i];

        int a = nums[i] + solve(i-2, l, dp, nums);
        int b = solve(i-1, l, dp, nums);

        return dp[i] = max(a,b);
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size(), INT_MIN);

        int a = solve(nums.size()-1, 1, dp, nums);
        vector<int> dp2(nums.size(), INT_MIN);
        int b = solve(nums.size()-2, 0, dp2, nums);

        return max(a,b);
    }
};
