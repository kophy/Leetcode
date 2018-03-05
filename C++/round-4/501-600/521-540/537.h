class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        vector<int> va = parseComplexNumber(a);
        vector<int> vb = parseComplexNumber(b);
        
        int r = va[0] * vb[0] - va[1] * vb[1];
        int i = va[0] * vb[1] + va[1] * vb[0];
        return to_string(r) + "+" + to_string(i) + "i";
    }
    
private:
    vector<int> parseComplexNumber(string &s) {
        int pos = 0;
        while (s[pos] != '+')
            ++pos;
        return {stoi(s.substr(0, pos)), stoi(s.substr(pos + 1, s.size() - 1))};
    }
};