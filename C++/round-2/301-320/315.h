class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int N = nums.size();
        vector<int> sorted, result(N);
        for (int i = N - 1; i >= 0; --i) {

            // Elements with same value as nums[i] should not be counted.
            auto pos = lower_bound(sorted.begin(), sorted.end(), nums[i]);

            result[i] = pos - sorted.begin();
            sorted.insert(pos, nums[i]);
        }
        return result;
    }
};