class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        map<int, int> index;
        for (int i = 0; i < nums.size(); ++i) {
            if (index.find(target - nums[i]) != index.end()) {
                result[0] = index[target - nums[i]];
                result[1] = i;
                break;
            } else {
                /*  Don't memorize index at the begin of the for-loop,
                	otherwise it's difficult to handle element with value equals target/2.
                */
                index[nums[i]] = i;
            }
        }
        return result;
    }
};