class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix.size(); j++){
                if(i == j || j<i)
                    continue;
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
