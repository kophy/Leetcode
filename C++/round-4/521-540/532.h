class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0)
            return 0;
        
        int result = 0;
        unordered_map<int, int> count;
        for (int num : nums)
            ++count[num];
        
        if (k == 0) {
            for (auto &p : count)
                if (p.second > 1)
                    ++result;
        } else {
            for (auto &p : count)
                if (count.count(p.first + k))
                    ++result;
        }
        
        return result;
    }
};