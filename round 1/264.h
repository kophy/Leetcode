class Solution {
public:
    int nthUglyNumber(int n) {
        int ct2 = 0, ct3 = 0, ct5 = 0;
        vector<int> result(n);
        result[0] = 1;
        for(int i  = 1; i < n ; i ++) {
            result[i] = min(result[ct2] * 2, min(result[ct3] * 3,result[ct5] * 5));
            if(result[i] == result[ct2] * 2)
                ++ct2;
            if(result[i] == result[ct3] * 3)
                ++ct3;
            if(result[i] == result[ct5] * 5)
                ++ct5;
        }
        return result[n - 1];
    }
};