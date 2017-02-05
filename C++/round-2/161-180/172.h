class Solution {
public:
    /*  trailing 0 are caused by factor 2 and 5
    	since number of 5 is less than 2, we only need to calculate the number of factor 5
    	and that's the number of trailing 0
    */
    int trailingZeroes(int n) {
        int result = 0;
        while (n) {
            n /= 5;
            result += n;
        }
        return result;
    }
};