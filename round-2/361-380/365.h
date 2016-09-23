class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z)
            return false;
        if (x > y)
            return canMeasureWater(y, x, z);
        if (x == 0)
            return (y == 0)? z == 0 : z % y == 0;
        else
            return z % gcd(x, y) == 0;
    }

private:
    int gcd(int x, int y) {
        return (y % x == 0)? x : gcd(y % x, x);
    }
};