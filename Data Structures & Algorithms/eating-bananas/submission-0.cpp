class Solution {
public:
    bool isValid(int mid, vector<int> &nums, int h){
    long long ans = 0;
    for(auto it: nums)
        ans += (it + mid -1)/mid;
    
    return ans <= h;
}

int minEatingSpeed(vector<int> nums, int h) {
    int l=1, r=*max_element(nums.begin(), nums.end());

    while(l < r){
        int mid = l + (r-l)/2;

        if(isValid(mid, nums, h))
            r=mid;
        else
            l=mid+1;
    }
    return l;
    }
};
