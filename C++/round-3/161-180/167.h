class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result(2, -1);
        int i = 0, j = (int)numbers.size() - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum < target)
                ++i;
            else if (sum > target)
                --j;
            else {
                result[0] = i + 1;
                result[1] = j + 1;
                break;
            }
        }
        return result;
    }
};