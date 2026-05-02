class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)   return 0;
        int l=0, r=0, ans=1;
        unordered_map<char, int> mp;

        while(r<s.size()){
            if(mp.find(s[r]) != mp.end()){
                l=max(l, mp[s[r]] +1 );
            }

            mp[s[r]] = r;
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int l = 0, r = 0, ans = 0;
//         unordered_map<char, int> mp;

//         while (r < s.size()) {
//             if (mp.find(s[r]) != mp.end()) {
//                 l = max(l, mp[s[r]] + 1);  // FIX: use s[r]
//             }

//             mp[s[r]] = r;  // always update latest index
//             ans = max(ans, r - l + 1);

//             r++;  // FIX: always move r
//         }

//         return ans;
//     }
// };