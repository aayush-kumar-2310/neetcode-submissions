class Solution {
public:
    int search(vector<int>& nums, int k) {
        int n = nums.size();
      int l=0, r=n-1;

      while(l<=r){
        int mid = l + (r-l)/2;

        if(nums[mid] == k)
            return mid;

        else if(nums[l] == nums[r] && nums[r] == nums[mid] && nums[l] == nums[mid]){
            l++;
            r--;
        }

        else if(nums[l] <= nums[mid]){
            if(nums[l] <= k && k < nums[mid])
                r = mid-1;
            else
                l = mid+1;
        }

        else if(nums[mid] <= nums[r]){
            if(nums[mid] < k && k <= nums[r])
                l = mid+1;
            else
                r = mid-1;
        }
      }
      return -1;
    }
};