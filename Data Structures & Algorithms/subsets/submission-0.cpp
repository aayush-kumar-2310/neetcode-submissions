class Solution {
public:

    void solve(int index, vector<int>& tmp, vector<vector<int>> &ans, vector<int>& nums){
        if(index == nums.size()){
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[index]);
        solve(index+1, tmp, ans, nums);
        tmp.pop_back();
        solve(index+1, tmp, ans, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(0, tmp, ans, nums);
        return ans;
    }
};
