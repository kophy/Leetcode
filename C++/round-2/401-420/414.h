class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> data;
        for (auto num : nums) {
            data.insert(num);
            if (data.size() > 3)
                data.erase(data.begin());
        }
        return data.size() < 3? *data.rbegin() : *data.begin();
    }
};