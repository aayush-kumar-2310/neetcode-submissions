class Solution {
public:
    int characterReplacement(string s, int k) {    
        unordered_map<char, int> mp;
        int l=0, r=0, ans=0, maxFreq=0;

        while(r<s.size()){
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);
            if(r-l+1-maxFreq > k){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }

        return ans;
    }
};


//window_size - max_frequent_element <= k