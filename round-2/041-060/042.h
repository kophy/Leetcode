class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
		int volume = 0, level = 0;
		while (l <= r) {
			level = max(level, min(height[l], height[r]));
			if (height[l] < height[r]) {
				volume += level - height[l];
				++l;
			} else {
				volume += level - height[r];
				--r;
			}
		}
		return volume;
    }
};