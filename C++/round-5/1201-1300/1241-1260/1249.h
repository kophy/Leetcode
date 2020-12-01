class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stringstream ss;
        int balance = 0;
        int total_open = 0;
        for (char c : s) {
            if (c == '(') {
                ++balance;
                ++total_open;
                ss << c;
            } else if (c == ')') {
                if (balance <= 0) {
                    continue;
                }
                --balance;
                ss << c;
            } else {
                ss << c;
            }
        }
        
        string t = ss.str();
        ss.str("");
        for (char c : t) {
            if (c == '(') {
                --total_open;
                if (total_open >= balance) {
                    ss << c;
                }
            } else {
                ss << c;
            }
        }
        return ss.str();
    }
};