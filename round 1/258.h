class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int temp = 0;
            while (num) {
                temp += num % 10;
                num /= 10;
            }
            num = temp;
        }
        return num;
    }
};