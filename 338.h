class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);

        int count = 1;
        int curr_pow2 = 1;

        while (count <= num) {
            result[curr_pow2] = 1;
            for (int j = 0; j < curr_pow2 && count <= num; ++j)
                result[count++] = result[j] + 1;
            curr_pow2 <<= 1;
        }

        return result;
    }
};