class Solution {
public:

    bool solve(vector<int>& piles, int mid, int h){
        int count = 0;
        for(int it: piles){
            if(it%mid == 0)
                count += it/mid;
            else count += it/mid + 1;
        }

        return count <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
       int l=1, r=*max_element(piles.begin(), piles.end());

        int ans = 0;
       while(l<=r){
        int mid = l + (r-l)/2;

        if(solve(piles, mid, h)){
            ans = mid;
            r=mid-1;
        }
        else
            l=mid+1;
       } 
       return ans;
    }
};
