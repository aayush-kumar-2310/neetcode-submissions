class Solution {

    public void solve(int index,
                      int target,
                      int[] nums,
                      List<Integer> tmp,
                      List<List<Integer>> ans) {

        if (target == 0) {
            ans.add(new ArrayList<>(tmp));
            return;
        }

        for (int i = index; i < nums.length; i++) {

            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            if (nums[i] > target) {
                break;
            }

            tmp.add(nums[i]);

            solve(i + 1,
                  target - nums[i],
                  nums,
                  tmp,
                  ans);

            tmp.remove(tmp.size() - 1);
        }
    }

    public List<List<Integer>> combinationSum2(int[] nums,
                                               int target) {

        Arrays.sort(nums);

        List<List<Integer>> ans = new ArrayList<>();

        solve(0,
              target,
              nums,
              new ArrayList<>(),
              ans);

        return ans;
    }
}