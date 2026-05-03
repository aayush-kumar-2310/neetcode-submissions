class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int have = 0, required = need.size();
        int l = 0;
        int minLen = INT_MAX, start = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (need.count(c) && window[c] == need[c]) {
                have++;
            }

            while (have == required) {
                if ((r - l + 1) < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                window[s[l]]--;
                if (need.count(s[l]) && window[s[l]] < need[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
