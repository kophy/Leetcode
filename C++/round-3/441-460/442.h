class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> count;
for (int num : nums)
            ++count[num];
        vector<int> result;
        for (auto iter = count.begin(); iter != count.end(); ++iter)
            if (iter->second == 2)
                result.push_back(iter->first);
        return result;
    }
};