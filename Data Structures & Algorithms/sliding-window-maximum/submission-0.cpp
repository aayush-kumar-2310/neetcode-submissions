class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0,r=0, maxi=INT_MIN;
        vector<int> ans;
        multiset<int> ms;
        while(r<nums.size()){
            while(r-l+1 < k){
                ms.insert(nums[r]);
                maxi = max(maxi, nums[r]);
                r++;
            }
            ms.insert(nums[r]);
            ans.push_back(*ms.rbegin());
            ms.erase(ms.find(nums[l]));
            l++;
            r++;
        }

        return ans;
    }
};
