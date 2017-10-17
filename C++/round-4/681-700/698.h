class Solution {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (nums.size() < k || sum % k != 0)
            return false;
        int target = sum / k;
        unordered_map<int, int> count;
        for (int num : nums)
            ++count[num];
        return dfs(count, target, k, 0, INT_MIN);
    }
    
private:
    // use "last" to force finding element in one split in increasing order
    bool dfs(unordered_map<int, int> &count, int target, int k, int current, int last) {
        if (k == 0)
            return true;
        for (auto &p : count) {
            if (p.second == 0 || p.first < last || current + p.first > target)
                continue;
            --p.second;
            if (current + p.first == target) {
                if (dfs(count, target, k - 1, 0, INT_MIN))
                    return true;
            } else {
                if (dfs(count, target, k, current + p.first, p.first))
                    return true;
            }
            ++p.second;
        }
        return false;
    }
};