class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        while (true) {
            slow = happy(slow);
            fast = happy(happy(fast));
            if (fast == 1)
                break;
            if (slow == fast)
                return false;
        }

        return true;
    }

private:
    int happy(int n) {
        int result = 0;
        while (n) {
            result += pow(n % 10, 2);
            n /= 10;
        }
        return result;
    }
};