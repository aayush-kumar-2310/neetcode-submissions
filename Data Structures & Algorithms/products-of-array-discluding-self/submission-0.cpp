class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());

        for(int i=0; i<nums.size(); i++){
            int prod=1;
            for(int j=0; j<nums.size(); j++){
                if(i == j)  continue;
                prod *= nums[j];
            }
            ans[i] = prod;
        }

        return ans;
    }
};
