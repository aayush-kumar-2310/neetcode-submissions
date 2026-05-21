class Solution {
   public:
    bool solve(vector<int>& weights, int mid, int days) {
    int count = 1;
    int curr = 0;

    for (int i = 0; i < weights.size(); i++) {
        if (curr + weights[i] > mid) {
            count++;
            curr = weights[i];
        }
        else {
            curr += weights[i];
        }
    }

    return count <= days;
}

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()), r = 0;
        for (int it : weights) r += it;
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (solve(weights, mid, days)) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }

        return ans;
    }
};