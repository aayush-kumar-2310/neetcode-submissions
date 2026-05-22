class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0) return;
        if (k >= nums.size()) k %= nums.size();

        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.begin(), nums.end());
    }
};