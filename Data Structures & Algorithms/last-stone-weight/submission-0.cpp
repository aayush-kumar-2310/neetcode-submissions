class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while(!pq.empty()){
            if(pq.size() == 1)
                return pq.top();
            int stoneOne = pq.top();
            pq.pop();
            int stoneTwo = pq.top();
            pq.pop();

            if(stoneOne != stoneTwo)
                pq.push(abs(stoneOne - stoneTwo));
        }

        return 0;
    }
};
