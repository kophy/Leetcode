class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int num = left; num <= right; ++num)
            if (isSelfDividingNumber(num))
                result.push_back(num);
        return result;
    }
    
private:
    bool isSelfDividingNumber(int num) {
        for (int n = num; n > 0; n /= 10) {
            int d = n % 10;
            if (d == 0 || num % d != 0)
                return false;
        }
        return true;
    }
};