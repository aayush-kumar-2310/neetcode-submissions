class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int a = 0, b = people.size() - 1;
        int ans = 0;
        while (a <= b) {
            if (people[a] + people[b] <= limit)
                a++;
            ans++;
            b--;
        }

        return ans;
    }
};