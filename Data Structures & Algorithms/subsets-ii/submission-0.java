class Solution {

    private void solve(int index, int[] nums, HashSet<List<Integer>> set, List<Integer> tmp){
        if(index == nums.length){
            set.add(new ArrayList<>(tmp));
            return;
        }

        for(int i=index; i<nums.length; i++){
            tmp.add(nums[i]);
            solve(i+1, nums, set, tmp);
            tmp.remove(tmp.size()-1);
            solve(i+1, nums, set, tmp);
        }
    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<Integer> tmp = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        HashSet<List<Integer>> set = new HashSet<>();

        solve(0, nums, set, tmp);

        for(List<Integer> it: set)
            ans.add(it);

        return ans;
    }
}
