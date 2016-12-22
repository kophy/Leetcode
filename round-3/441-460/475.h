class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int result = INT_MIN;

        /* assign each house to nearest heater */
        for (int i = 0; i < houses.size(); ++i) {
            int dist = INT_MAX;
            // binary search to accelerate
            int larger = lower_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();
            if (larger < heaters.size())
                dist = min(dist, abs(houses[i] - heaters[larger]));
            if (larger > 0)
                dist = min(dist, abs(houses[i] - heaters[larger - 1]));
            result = max(result, dist);
        }
        return result;
    }
};