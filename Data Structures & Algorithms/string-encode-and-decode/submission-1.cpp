class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";

        for(auto s: strs){
            int n = s.size();
            encodedString += to_string(n) + "_" + s;
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i=0;
        while(i<s.size()){
            int num = 0;

            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            
            i++;

            string word = s.substr(i, num);
            ans.push_back(word);

            i+=num;
        }
        return ans;
    }
};
