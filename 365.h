class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z)
            return false;
        else {
            int g = gcd(x, y);
            if (g == 0)
                return (z == 0);
            else
                return (z % g == 0);
        }
    }
private:
    int gcd(int x, int y) {
        if (x > y)
            return gcd(y, x);
        if (x == 0)
            return 0;
        else if (y % x == 0)
            return x;
        else
            return gcd(y % x, x);
    }

};