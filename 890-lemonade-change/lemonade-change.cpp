class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        vector<int> notes(3,0);
        if(bills[0] != 5) return false;

        for(int i=0; i<n; i++)
        {
            if(bills[i] == 5)
                notes[0]++;
            if(bills[i] == 10)
            {
                if(notes[0]<1)
                    return false;
                else
                    notes[0]--;
                notes[1]++;
            }
            if(bills[i] == 20)
            {
                if(notes[0] >= 1 && notes[1] >= 1)
                {
                    notes[2]++;
                    notes[0] --;
                    notes[1] --;
                }
                else if(notes[0]*5 >= 15)
                {
                    notes[2]++;
                    notes[0] -= 3;
                }
                else 
                    return false;
            }
        }
        if(notes[0] < 0 || notes[1] < 0)
            return false;
        return true;
    }
};