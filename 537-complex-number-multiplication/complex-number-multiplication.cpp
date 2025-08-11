class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int pos1 = num1.find('+'), pos2 = num2.find('+'),
            a = stoi(num1.substr(0,pos1)), b = stoi(num1.substr(pos1+1)), 
            c = stoi(num2.substr(0,pos2)), d = stoi(num2.substr(pos2+1)),
            real = a*c - b*d, img = a*d + b*c;
        return to_string(real) + '+' + to_string(img) + 'i';
    }
};