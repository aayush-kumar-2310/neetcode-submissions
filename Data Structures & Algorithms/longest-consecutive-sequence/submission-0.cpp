class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers(nums.begin(), nums.end());

        int tmp=0, ans=0;

        for(auto it: nums){
            if(numbers.find(it) != numbers.end()){
                tmp=1;
                int num = it;
                while(numbers.find(++num) != numbers.end())
                    tmp++;
                ans = max(ans, tmp);
            }
        }

        return ans;
    }
};
