class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int soln = 0;
        while(left<right)
        {
            if(height[left] < height[right])
            {
                soln = max(soln, height[left]*(right-left));
                left++;
            }
            else
            {
                soln = max(soln, height[right]*(right-left));
                right--;
            }
        }
        return soln;
    }
};