class Solution {
   public:
    bool canSolve(vector<int>& nums, int k, int mid) {
        int count = 1;
        int curr = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (curr + nums[i] > mid) {
                count++;
                curr = nums[i];
            } else
                curr += nums[i];
        }

        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);

        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canSolve(nums, k, mid)) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }

        return ans;
    }
};