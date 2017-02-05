class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        while (n) {
            int d = (n - 1) % 26;
            result = char2str(char('A' + d)) + result;
            n = (n - 1) / 26;
        }
        return result;
    }
private:
    string char2str(char c) {
        stringstream ss;
        ss << c;
        return ss.str();
    }
};