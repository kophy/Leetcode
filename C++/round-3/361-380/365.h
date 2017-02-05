class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z)
            return false;
        else if (z == 0)
            return true;
        else if (x == 0)
            return (y == z);
        else if (y == 0)
            return (x == z);
        else
            return (z % gcd(x, y) == 0);
    }

private:
    int gcd(int x, int y) {
        if (x > y)
            return gcd(y, x);
        if (y % x == 0)
            return x;
        else
            return gcd(y % x, x);
    }
};