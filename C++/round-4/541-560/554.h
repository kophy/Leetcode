class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> skip_count;
        for (auto &v : wall) {
            int offset = 0;
            for (int i = 0; i < v.size() - 1; ++i) {
                offset += v[i];
                ++skip_count[offset];
            }
        }
        // we must cut every level
        if (skip_count.empty())
            return wall.size();
        int best_offset = skip_count.begin()->first;
        for (auto &p : skip_count)
            if (skip_count[best_offset] < p.second)
                best_offset = p.first;
        return wall.size() - skip_count[best_offset];
    }
};