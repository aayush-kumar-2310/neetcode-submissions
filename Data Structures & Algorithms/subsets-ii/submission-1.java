class Solution {

    private void solve(int index,
                       int[] nums,
                       List<Integer> tmp,
                       List<List<Integer>> ans) {

        if (index == nums.length) {
            ans.add(new ArrayList<>(tmp));
            return;
        }

        tmp.add(nums[index]);
        solve(index + 1,
              nums,
              tmp,
              ans);

        tmp.remove(tmp.size() - 1);

        while (index + 1 < nums.length &&
               nums[index] == nums[index + 1]) {

            index++;
        }

        solve(index + 1,
              nums,
              tmp,
              ans);
    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {

        Arrays.sort(nums);

        List<List<Integer>> ans = new ArrayList<>();

        solve(0,
              nums,
              new ArrayList<>(),
              ans);

        return ans;
    }
}