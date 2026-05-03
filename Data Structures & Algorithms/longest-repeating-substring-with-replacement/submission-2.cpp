class Solution {
public:
    int characterReplacement(string s, int k) {    
        vector<int> freq(26, 0);
        int l=0, r=0, ans=0, maxFreq=0;

        while(r<s.size()){
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);
            if(r-l+1-maxFreq > k){
                freq[s[l] - 'A']--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }

        return ans;
    }
};


//window_size - max_frequent_element <= k