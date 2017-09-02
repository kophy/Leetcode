class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1)
            return 0;
        int max_area = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            int lh = height[l], rh = height[r];
            max_area = max(max_area, (r - l) * min(lh, rh));
			// shrink one side
            if (lh < rh) {
                while (l < r && height[l] <= lh)
                    ++l;
            } else {
                while (l < r && height[r] <= rh)
                    --r;
            }
        }
        return max_area;
    }
};