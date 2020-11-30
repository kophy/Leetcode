class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            ++count[num];
        }
        int result = 0;
        for (const auto &p : count) {
            result += p.second * (p.second - 1) / 2;
        }
        return result;
    }
};