class Solution {
public:
    vector<int> constructRectangle(int area) {
		vector<int> result(2, 0);
		int diff = INT_MAX, bound = sqrt(area) + 1;
        for (int i = 1; i <= bound; ++i) {
			if (area % i)
				continue;
			if (abs(i - area / i) < diff) {
				result[0] = i;
				result[1] = area / i;
				diff = abs(i - area / i);
			}
		}
		sort(result.begin(), result.end(), greater<int>());
		return result;
    }
};