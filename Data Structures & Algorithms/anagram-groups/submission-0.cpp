class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> keyMap;

        for(auto it: strs){
            string temp = it;
            sort(temp.begin(), temp.end());
            keyMap[temp].push_back(it);
        }

        vector<vector<string>> ans;
        for(auto it: keyMap){
            ans.push_back(it.second);
        }

        return ans;
    }
};
