class Solution {

    void solve(boolean[] vis, int[] nums, List<Integer> tmp, List<List<Integer>> ans){
        if(tmp.size() == nums.length){
            ans.add(new ArrayList<>(tmp));
            return;
        }

        for(int i=0; i<nums.length; i++){
            if(vis[i])
                continue;
            vis[i] = true;
            tmp.add(nums[i]);
            solve(vis, nums, tmp, ans);
            tmp.remove(tmp.size()-1);
            vis[i] = false;
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        List<Integer> tmp = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        
        boolean[] vis = new boolean[nums.length];

        solve(vis, nums, tmp, ans);
        return ans;
    }
}
