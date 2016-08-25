class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int max_area = (r - l) * min(height[l], height[r]);

        while (l < r) {
            if (height[l] < height[r]) {
                int hl = height[l];
                while (l < r && height[l] <= hl)
                    ++l;

            } else {
                int hr = height[r];
                while (l < r && height[r] <= hr)
                    --r;
            }
            if (l < r) {
                int area = (r - l) * min(height[l], height[r]);
                max_area = max(area, max_area);
            }
        }

        return max_area;
    }
};