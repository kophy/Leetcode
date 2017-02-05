class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2)
            return 0;
        int l = 0, r = height.size() - 1;
        int max_area = (r - l) * min(height[l], height[r]);

        while (l < r) {
            int old_level = min(height[l], height[r]);

            /*  container shrinks in x direction, so the volume won't increase
            	unless new level is larger than old level.
            */
            if (height[l] < height[r]) {
                while (l < r && height[l] <= old_level)
                    ++l;
            } else {
                while (l < r && height[r] <= old_level)
                    --r;
            };
            int curr_area = (r - l) * min(height[l], height[r]);
            max_area = max(max_area, curr_area);
        }

        return max_area;
    }
};