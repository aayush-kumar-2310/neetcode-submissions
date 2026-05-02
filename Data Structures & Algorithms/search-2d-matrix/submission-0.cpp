class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int l=0, r=mat.size()*mat[0].size()-1;

        while(l <= r){
            int mid = l + (r-l)/2;
            int x=mid/mat[0].size(), y=mid%mat[0].size();
            if(mat[x][y] == target)
                return true;
            else if(mat[x][y] > target)
                r=mid-1;
            else
                l=mid+1;
        }
        return false;
    }
};
