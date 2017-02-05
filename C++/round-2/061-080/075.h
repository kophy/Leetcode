class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = -1, blue = nums.size();
        int pos = 0;
        /*  the array is divided into 4 parts
        	1. from head to red					all red elements
        	2. from (red + 1) to (pos - 1)		all white elements
        	3. from pos to (blue - 1)			waiting for judge
        	4. from blue to end					all blue elements
        */
        while (pos < blue) {
            if (nums[pos] == 0)
                swap(nums[pos++], nums[++red]);
            else if (nums[pos] == 1)
                pos++;
            else
                swap(nums[pos], nums[--blue]);
        }
    }
};