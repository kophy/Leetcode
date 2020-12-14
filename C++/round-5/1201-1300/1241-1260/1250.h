class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            g = gcd(g, nums[i]);
            if (g == 1) {
                return true;
            }
        }
        return false;
    }
    
private:
    int gcd(int x, int y) {
        if (x % y == 0) {
            return y;
        }
        if (x > y) {
            return gcd(y, x % y);
        } else if (x == y) {
            return x;
        } else {
            return gcd(y, x);
        }
    }
};