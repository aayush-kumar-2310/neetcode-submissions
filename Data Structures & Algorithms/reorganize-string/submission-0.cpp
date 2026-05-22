class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char,int> freq;

        for(char ch : s) {
            freq[ch]++;

            if(freq[ch] > (s.size() + 1) / 2)
                return "";
        }

        priority_queue<pair<int,char>> pq;

        for(auto it : freq)
            pq.push({it.second, it.first});

        string ans = "";

        while(pq.size() >= 2) {

            auto first = pq.top();
            pq.pop();

            auto second = pq.top();
            pq.pop();

            ans += first.second;
            ans += second.second;

            first.first--;
            second.first--;

            if(first.first > 0)
                pq.push(first);

            if(second.first > 0)
                pq.push(second);
        }

        if(!pq.empty())
            ans += pq.top().second;

        return ans;
    }
};