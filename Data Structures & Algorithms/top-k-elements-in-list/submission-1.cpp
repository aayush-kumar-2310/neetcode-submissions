class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        for (auto it : nums) count[it]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (auto it : count) {
            pq.push({it.second, it.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;
        while (k) {
            pair<int, int> tmp = pq.top();
            ans.push_back(tmp.second);
            pq.pop();
            k--;
        }

        return ans;
    }
};
