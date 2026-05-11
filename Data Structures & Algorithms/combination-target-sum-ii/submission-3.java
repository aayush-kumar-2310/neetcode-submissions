class Solution {

    public void solve(int index, int target, int[] nums, 
        List<Integer> tmp, List<List<Integer>> ans, int sum){

            if(target == sum){
                ans.add(new ArrayList<>(tmp));
                return ;
            }     

            for(int i=index; i<nums.length; i++){
                if(i>index && nums[i] == nums[i-1])
                    continue;

                if(nums[i] > target - sum)
                    break;

                tmp.add(nums[i]);
                solve(i+1, target, nums, tmp, ans, sum+nums[i]);
                tmp.remove(tmp.size()-1);
            }
    } 

    public List<List<Integer>> combinationSum2(int[] nums, int target) {
        List<Integer> tmp = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        solve(0, target, nums, tmp, ans, 0);


        return ans;
    }
}
