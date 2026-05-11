class Solution {
    private void solve(int n, int open, int close, List<String> ans, StringBuilder tmp){
        
        if(open == close && open == n){
            ans.add(tmp.toString());
            return;
        }
        
        if(close<open){
            tmp.append(')');
            solve(n, open, close+1, ans, tmp);
            tmp.deleteCharAt(tmp.length()-1);
        }

        if(open<n){
            tmp.append('(');
            solve(n, open+1, close, ans, tmp);
            tmp.deleteCharAt(tmp.length()-1);
        }

    }
    public List<String> generateParenthesis(int n) {
        StringBuilder tmp = new StringBuilder();
        List<String> ans = new ArrayList<>();
        
        solve(n, 0, 0, ans, tmp);
        return ans;
    }
}
