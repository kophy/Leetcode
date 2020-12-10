class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        if (nums.size() < 2) {
            return -1;
        }
        
        map<int, int> count;
        for (int num : nums) {
            ++count[num];
        }
        
        int max_sum = -1;
        for (int num : nums) {
            if (--count[num] == 0) {
                count.erase(num);
            }
            auto iter = count.lower_bound(k - num);
            if (iter == count.begin()) {
                continue;
            }
            --iter;
            max_sum = max(max_sum, num + iter->first);
        }
        return max_sum;
    }
};