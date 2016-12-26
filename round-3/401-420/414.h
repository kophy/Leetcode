class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> largest3;
        for (int num : nums) {
            largest3.insert(num);
            if (largest3.size() > 3)
                largest3.erase(largest3.begin());
        }
        return largest3.size() == 3? *largest3.begin() : *largest3.rbegin();
    }
};