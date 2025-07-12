class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        vector<int> nge(n2);
        
        stack<int> st;
        st.push(nums2[n2-1]);
        nge[n2-1] = -1;
        
        for(int i=n2-2; i>=0; i--)
        {
            if(nums2[i] < st.top())
            {
                nge[i] = st.top();
                st.push(nums2[i]);
            }
            else
            {
                while(st.empty() == false && nums2[i] >= st.top())
                {
                    st.pop();
                }
                if(st.empty() == true) 
                {
                    nge[i] = -1;
                    st.push(nums2[i]);
                }
                else
                {
                    nge[i] = st.top();
                    st.push(nums2[i]);
                }
            }
        }
        vector<int> soln(n1);
        for(int i=0; i<n1; i++)
        {
            for(int j=0; j<n2; j++)
            {
                if(nums1[i] == nums2[j])
                {
                    soln[i] = nge[j];
                    break;
                }
            }
        }
        return soln;
    }
};