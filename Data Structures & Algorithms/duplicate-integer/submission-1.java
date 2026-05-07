class Solution {
    public boolean hasDuplicate(int[] nums) {
        HashSet<Integer> set = new HashSet<>();

        for(Integer it: nums){
            if(set.contains(it))
                return true;
            set.add(it);
        }
        return false;
    }
}