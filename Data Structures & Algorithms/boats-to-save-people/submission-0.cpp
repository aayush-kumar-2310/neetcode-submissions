class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int a=0, b=people.size()-1;
        int ans=0;
        while(a<=b){
            if(people[b] > limit)
                return -1;
            else if(people[a] + people[b] <= limit){
                ans++;
                a++;
                b--;
            }
            else{
                if(people[b] <= limit){
                    ans++;
                    b--;
                }
            }
        }

        return ans;
    }
};