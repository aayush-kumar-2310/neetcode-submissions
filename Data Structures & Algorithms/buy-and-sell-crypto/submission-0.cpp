class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prefix(n);
        prefix[n-1] = prices[n-1];

        for(int i=n-2; i>=0; i--){
            prefix[i] = max(prices[i], prefix[i+1]);
        }

        int ans = 0;

        for(int i=0; i<n; i++){
            ans = max(ans, abs(prices[i]-prefix[i]));
        }

        return ans;
    }
};
