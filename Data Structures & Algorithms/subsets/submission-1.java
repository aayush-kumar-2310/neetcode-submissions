class Solution {

    public void solve(int index, List<Integer> tmp, List<List<Integer>> ans, int[] nums){
        if(index == nums.length){
            ans.add(new ArrayList<>(tmp));
            return;
        }

        tmp.add(nums[index]);
        solve(index+1, tmp, ans, nums);
        tmp.remove(tmp.size()-1);
        solve(index+1, tmp, ans, nums);
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> tmp = new ArrayList<>();

        solve(0, tmp, ans, nums);
        return ans;
    }
}
