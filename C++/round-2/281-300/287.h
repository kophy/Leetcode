/* pseudo radix sort */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int N = nums.size() - 1;
        vector<int> bucket(N + 1, 0);
for (int num : nums)
            if (++bucket[num] > 1)
                return num;
        return 0;
    }
};