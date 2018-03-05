class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1)
            return false;
        
        int temp = 1;
        for (int i = 2; i <= (int)sqrt(num); ++i)
            if (num % i == 0) {
                temp += i;
                if (num != i * i)
                    temp += num / i;
            }
        return temp == num;
    }
};