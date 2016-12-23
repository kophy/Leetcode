class Solution {
public:
    string toHex(int num) {
        string result = "";
        for (int count = 0; count < 8; ++count) {
            int temp = num & 15;
            if (temp < 10)
                result.push_back('0'+ temp);
            else
                result.push_back('a'+temp-10);
            num = num >> 4;
            if (num == 0)
                break;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};