class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.size() == 0 || dungeon[0].size() == 0)
            return 0;
        int M = dungeon.size(), N = dungeon[0].size();

        /*  there are two steps at each point:
        	1. change HP
        	2. move on to reach destination
        	and HP should be no less than 1 after each step
        	so it's easiter to calculate from end back to beginning
        */
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {

                // calculate minimum HP required to reach destination (step 2)
                int t = INT_MAX;
                if (i < M - 1)
                    t = dungeon[i + 1][j];
                if (j < N - 1)
                    t = min(t, dungeon[i][j + 1]);
                if (t == INT_MAX)
                    t = 1;

                // calculate minimum HP required to stay alive (step 1)
                dungeon[i][j] = max(1, t - dungeon[i][j]);
            }
        }
        return dungeon[0][0];
    }
};