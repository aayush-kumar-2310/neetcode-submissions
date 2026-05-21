class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0, r=matrix.size()*matrix[0].size()-1;

        while(l<=r){
            int mid = l + (r-l)/2;
            int m = mid/matrix[0].size(), n = mid%matrix[0].size();

            if(matrix[m][n] == target)
                return true;
            else if(matrix[m][n] > target){
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return false;
    }
};
