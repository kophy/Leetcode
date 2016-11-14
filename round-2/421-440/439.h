class Solution {
public:
    string parseTernary(string expression) {
        int pos = 0;
        return parse(expression, pos);
    }

private:
    string parse(string &exp, int &pos) {
        string result;
        if (pos < exp.size()) {
            // case 1: digit, get whole number
            if (isdigit(exp[pos])) {
                int i = 0;
                while (isdigit(exp[pos + i]))
                    ++i;
                result = exp.substr(pos, i);
                pos += i + 1;
            }
            // case 2: 'T' or 'F'
            else if (exp[pos] == 'T' || exp[pos] == 'F') {
                // case 2.1: ternary
                if (pos + 1 < exp.size() && exp[pos + 1] == '?') {
                    bool flag = exp[pos] == 'T';
                    pos += 2;
                    string left = parse(exp, pos), right = parse(exp, pos);
                    result = flag? left : right;
                }
                // case 2.2: just a string
                else {
                    result.push_back(exp[pos]);
                    pos += 2;
                }
            }
        }
        return result;
    }
};