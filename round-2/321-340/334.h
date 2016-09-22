class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3)
            return false;

        /*  Idea is always the same... keep track of only two elements.
        	When an increasing triple appears, return true;
        	otherwise update two elements if current element is smaller than them.
        */
        vector<int> result;
        result.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            /*  The most brilliant part.
            	Updating the second element is trivial, but updating the first element will cause the two
            	elements not in order.
            	Here we only care existence, so we don't have to know if there is a specific increasing triple.
            */
            if (nums[i] <= result[0])
                result[0] = nums[i];
            else if (result.size() == 1)
                result.push_back(nums[i]);
            else if (nums[i] <= result[1])
                result[1] = nums[i];
            else
                return true;
        }
        return false;
    }
};