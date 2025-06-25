class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int Lsum = 0, Rsum = 0;
        int Lptr = 0, Rptr = n-1;
        for(int i=0; i<k; i++)
        {
            Lsum += cardPoints[i];
            Lptr = i;
        }
        if(k==n)
            return Lsum;
        int maxSum = Lsum;
        int count = k;
        while(count>0)
        {
            Lsum -= cardPoints[Lptr];
            Lptr--;
            Rsum += cardPoints[Rptr];
            Rptr--;
            maxSum = max(maxSum, Lsum+Rsum);
            count --;
        }
        return maxSum;
    }
};