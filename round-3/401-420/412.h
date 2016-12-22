class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n);
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 && i % 5 == 0)
                result[i - 1] = "FizzBuzz";
            else if (i % 3 == 0)
                result[i - 1] = "Fizz";
            else if (i % 5 == 0)
                result[i - 1] = "Buzz";
            else
                result[i - 1] = to_string(i);
        }
        return result;
    }
};