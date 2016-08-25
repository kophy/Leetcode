class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        while (true) {
            slow = next(slow);
            fast = next(next(fast));
            if (slow == 1)
                return true;
            if (slow == fast)
                return false;
        }
    }
private:
    int next(int n) {
        int sum = 0;
        while (n) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
};