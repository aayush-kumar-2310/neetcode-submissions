class Solution {

    public void solve(int index, int target, int[] nums, 
        List<Integer> tmp, List<List<Integer>> ans, int sum){

            if(index == nums.length){
                if(sum == target){
                    ans.add(new ArrayList<>(tmp));
                }
                return;
            }
            else if(target == sum){
                ans.add(new ArrayList<>(tmp));
                return ;
            }     
            else if(sum > target) return;

            tmp.add(nums[index]);
            solve(index, target, nums, tmp, ans, sum+nums[index]);
            tmp.remove(tmp.size()-1);
            solve(index+1, target, nums, tmp, ans, sum);
    } 

    public List<List<Integer>> combinationSum(int[] nums, int target) {
        List<Integer> tmp = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();

        solve(0, target, nums, tmp, ans, 0);
        return ans;
    }
}
