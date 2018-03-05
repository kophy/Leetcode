class Solution {
public:
    bool judgePoint24(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        while (true) {
            if (valid(nums))
                return true;
            // traverse all permutations, no need to check both a - b and b - a
            if(!next_permutation(nums.begin(), nums.end()))
                return false;
        }
        return false;
    }
private:
    double eps = 0.0001;
    
    // reduce 4 numbers to 3 numbers
    bool valid(vector<int> &nums) {
        double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        if (valid(a + b, c, d) || valid(a - b, c, d) || valid(a * b, c, d) || valid(a / b, c, d))
            return true;
        if (valid(a, b + c, d) || valid(a, b - c, d) || valid(a, b * c, d) || valid(a, b / c, d))
            return true;
        if (valid(a, b, c + d) || valid(a, b, c - d) || valid(a, b, c * d) || valid(a, b, c / d))
            return true;
        return false;
    }
    
    // reduce 3 numbers to 2 numbers
    bool valid(double a, double b, double c) {
        if (valid(a+b, c) || valid(a-b, c) || valid(a*b, c) || b&&valid(a/b, c))
            return true;
        if (valid(a, b+c) || valid(a, b-c) || valid(a, b*c) || c&&valid(a, b/c))
            return true;
        return false;
    }
    
    // check all cases for 2 numbers
    bool valid(double a, double b) {
        if (abs(a + b - 24.0) < eps || abs(a - b - 24.0) < eps || abs(a * b - 24.0) < eps || b && abs(a / b - 24.0) < eps) 
            return true;
        return false;
    }
};