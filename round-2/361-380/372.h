class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int result = 1;
        int a_i = a % 1337;     // important to avoid overflow in the first place!

        for (int i = b.size() - 1; i >= 0; --i) {
            for (int j = 0; j < b[i]; ++j)
                result = (result * a_i) % 1337;
            int temp = 1;
            for (int j = 0; j < 10; ++j)
                temp = (temp * a_i) % 1337;
            a_i = temp;
        }
        return result;
    }
};