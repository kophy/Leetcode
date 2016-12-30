class Solution {
public:
    int addDigits(int num) {
        if (num % 9 == 0)
            return (num == 0)? 0 : 9;
        return num % 9;
    }
};