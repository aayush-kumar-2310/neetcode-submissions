class Solution {
public:
    bool isAnagram(string s, string t) {
        string k1="", k2="";
        vector<int> tmp(26,0);

        for(auto it: s)
            tmp[it-'a']++;

        for(auto it: tmp)
            k1 += "#" + to_string(it);

        tmp = vector<int>(26, 0);
        for(auto it: t)
            tmp[it-'a']++;

        for(auto it: tmp)
            k2 += "#" + to_string(it);
        
        return k1==k2;
    }
};
