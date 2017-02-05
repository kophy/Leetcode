class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> index;
        for (int i = 0; i < nums.size(); ++i) {
            int d = nums[i];
            if (index.find(d) != index.end())
                if (i - index[d] <= k)
                    return true;
            index[d] = i;
        }
        return false;
    }
};