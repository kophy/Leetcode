class Solution {
public:
    int numDecodings(string s) {
        if (!s.size())
            return 0;
        vector<int> nums(s.size() + 1, 0);
        int N = s.size();

        nums[N] = 1;
        nums[N - 1] = digit(s[N - 1])? 1 : 0;

        for (int i = s.size() - 2; i >= 0; --i) {
            if (digit(s[i])) {
                int temp = digit(s[i]) * 10  + digit(s[i + 1]);
                nums[i] = (temp > 0 && temp<= 26)? (nums[i + 1] + nums[i + 2]) : nums[i + 1];
            }
        }
        return nums[0];
    }
private:
    int digit(char d) {
        return (d - '0');
    }
};