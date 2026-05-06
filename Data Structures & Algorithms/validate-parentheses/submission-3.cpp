class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '}' || s[i] == ']'){
                st.push(s[i]);
            }
            else if (!st.empty() && ((s[i] == '(' && st.top() == ')') || (s[i] == '[' && st.top() == ']') ||
                     (s[i] == '{' && st.top() == '}'))){
                st.pop();
            }
            else
                return false;
        }
        if (st.size() == 0) return true;
        return false;
    }
};
