class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        for (int r = dungeon.size()-1; r >= 0; --r) {
            for (int c = dungeon[0].size() - 1; c >= 0; --c) {
                int t = INT_MAX;
                if (c < dungeon[0].size() - 1)
                    t = dungeon[r][c+1];
                if (r < dungeon.size() - 1)
                    t = min(t, dungeon[r + 1][c]);
                t = (t == INT_MAX)? 1 : t;
                dungeon[r][c] = max(1, t - dungeon[r][c]);
            }
        }
        return dungeon[0][0];
    }
};