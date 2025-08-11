class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result; 
        for (int i = 0; i <  mat.size() + mat[0].size() - 1; i++){
            if (i % 2 == 0){
                // from bottom to up
                for (int col = max (0, i - (int)mat.size() + 1); col < min ((int)mat[0].size(), i + 1); col++){
                    int row = i - col; 
                    result.push_back (mat[row][col]);
                }
                
            }
            else {
               for (int row = max (0, i - (int)mat[0].size() + 1); row < min ((int)mat.size(), i + 1); row++){
                    int col = i - row; 
                   result.push_back (mat[row][col]);
               }
            }
        }
             return result; 
    }
};