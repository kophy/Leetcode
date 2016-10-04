class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        string result;
        for (int i = 0; i < 8 && num; ++i) {
            int d = num & 15;
            num >>= 4;
            result.push_back(d < 10? '0' + d : 'a' + d - 10);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};