class Solution {
public:
    int superPow(int a, vector<int>& b) {
        a %= 1337;
        int result = 1;
        for (int i = b.size() - 1; i >= 0; --i) {
            for (int j = 0; j < b[i]; ++j)
                result = (result * a) % 1337;
            int temp = 1;
            for (int j = 0; j < 10; ++j)
                temp = (temp * a) % 1337;
            a = temp;
        }
        return result;
    }
};