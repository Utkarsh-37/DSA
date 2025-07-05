class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string soln = "";
        
        int count = 1;
        for(int i=0; i<n; i++)
        {
            if(s[i]==' ' && count==1)
            {
                continue;
            }
            if(s[i]==' ')
                count = 1;
            else
                count = 0;
            
            soln += s[i];
        }
        for(int i=soln.length()-1; i>=0; i--)
        {
            if(soln[i]==' ')
                continue;
            soln = soln.substr(0,i+1);
            break;
        }

        cout<<soln;
        string soln1 = "";
        int index = soln.length()-1;
        for(int i=soln.length()-1; i>=0; i--)
        {
            if(soln[i]==' ')
            {
                soln1 += soln.substr(i+1,index-i);
                soln1 += " ";
                index = i-1;
            }
            if(i==0)
            {
                soln1 += soln.substr(i,index+1);
            }
        }
        
        return soln1;
    }
};