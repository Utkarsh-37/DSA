class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low1 = 0, high1 = n-1;
        int low2 = 0, high2 = m-1;
        int row = -1, col = -1;
        while(low1 <= high1)
        {
            int mid = (low1 + high1)/2;
            if(matrix[mid][0] > target)
                high1 = mid -1;
            else
            {
                row = mid;
                low1 = mid + 1;
            }        
        }
        if(row == -1)
            return false;

        while(low2 <= high2)
        {
            int mid = (low2 + high2)/2;
            if(matrix[row][mid] == target)
                return true;
            else if(matrix[row][mid] > target)
                high2 = mid - 1;
            else
                low2 = mid + 1;
        }
        return false;
    }
};