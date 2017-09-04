class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() <= 2)
			return 0;
		int l = 0, r = height.size() - 1, h = min(height[l], height[r]);
		int volumn = 0;
		while (l <= r) {
			if (height[l] < height[r]) {
				if (height[l] < h)
					volumn += h - height[l];
				++l;
			} else {
				if (height[r] < h)
					volumn += h - height[r];
				--r;
			}
			h = max(h, min(height[l], height[r]));
		}
		return volumn;
	}
};