class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)
            return true;
        int begin = 0;
        int end = num / 2;

        while(begin <= end) {
            long middle = (begin + end) / 2;
            if(middle * middle == num)
                return true;
            else if(middle * middle < num)
                begin = middle + 1;
            else
                end = middle - 1;
        }
        return false;
    }
};