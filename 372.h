class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int result = 1;
        int apcurr = a % 1337;
        for (int i = b.size() - 1; i >= 0; --i) {
            for (int j = 0; j < b[i]; ++j) {
                result = (result * apcurr) % 1337;
            }
            int aptemp = apcurr;
            for (int k = 0; k < 9; ++k) {
                apcurr = (apcurr * aptemp) % 1337;
            }
        }
        return result;
    }
};