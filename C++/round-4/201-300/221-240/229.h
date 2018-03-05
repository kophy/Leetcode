class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> candidate = {0, 1};
        vector<int> count = {0, 0};
        
        // let each element poll
        for (int num : nums) {
            if (num == candidate[0])
                ++count[0];
            else if (num == candidate[1])
                ++count[1];
            else if (count[0] == 0) {
                candidate[0] = num;
                count[0] = 1;
            }
            else if (count[1] == 0) {
                candidate[1] = num;
                count[1] = 1;
            }
            else {
                --count[0];
                --count[1];
            }
        }
        
        // verify whether candidate is majority element
        count[0] = count[1] = 0;
        for (int num : nums) {
            if (num == candidate[0])
                ++count[0];
            else if (num == candidate[1])
                ++count[1];
        }
        
        vector<int> result;
        if (count[0] > nums.size() / 3)
            result.push_back(candidate[0]);
        if (count[1] > nums.size() / 3)
            result.push_back(candidate[1]);
        return result;
    }
};