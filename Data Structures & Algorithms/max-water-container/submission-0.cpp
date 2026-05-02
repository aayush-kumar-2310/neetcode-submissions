class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int ans=0;

        for(int i=0; i<n; i++){
            int tmp=0;
            for(int j=i+1; j<n; j++){
                tmp = min(heights[i], heights[j])*(abs(i-j));
                ans = max(tmp, ans);
            }
        }

        return ans;
    }
};
