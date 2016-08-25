class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int level = 0;
        int water = 0;
        while (left < right) {
            int lower = min(height[left], height[right]);
            if (lower == height[left])
                ++left;
            else
                --right;
            level = max(level, lower);
            water += level - lower;
        }
        return water;
    }
};