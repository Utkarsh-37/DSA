class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> soln(n, -2);
        stack<int> st;
        // only change from nge 1 is that we treat the arr size as twice with suplicate elements and make all changes in stack for the second half, then do the regular soln

        for(int i=n-1; i>=0; i--)
        {
            while(st.empty() == false && st.top() <= nums[i])
                st.pop();
            st.push(nums[i]);
        }

        for(int i=n-1; i>=0; i--)
        {
            while(st.empty() == false && st.top() <= nums[i])
                st.pop();
            if(st.empty())
                soln[i] = -1;
            else
                soln[i] = st.top();
            st.push(nums[i]);
        }
        return soln;
    }
};