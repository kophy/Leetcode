/* Solution 1: brute-force traverse */
class Solution {
public:
    bool isSelfCrossing(vector<int> &data) {
        int dire_x[4] = {0, -1,  0, 1};
        int dire_y[4] = {1,  0, -1, 0};

        set<pair<int, int>, pointcmp> visited;
        visited.insert(make_pair(0, 0));

        int x = 0, y = 0;
        for (int i = 0; i < data.size(); ++i) {
            for (int j = 0; j < data[i]; ++j) {
                x += dire_x[i % 4];
                y += dire_y[i % 4];
                auto curr_pos = make_pair(x, y);
                if (visited.find(curr_pos) != visited.end())
                    return true;
                else
                    visited.insert(curr_pos);
            }
        }
        return false;
    }

private:
    /* define customized comparator */
    struct pointcmp {
        bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
            return a.first < b.first || (a.first == b.first && a.second < b.second);
        };
    };
};

/* Solution 2: analyze 3 cases self-crossing happens */
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        for(int i = 3; i < x.size(); ++i) {
            // Case 1: current line crosses the line 3 steps ahead of it
            if(x[i] >= x[i - 2] && x[i - 1] <= x[i - 3])
                return true;
            // Case 2: current line crosses the line 4 steps ahead of it
            else if(i > 3 && x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2])
                return true;
            // Case 3: current line crosses the line 6 steps ahead of it
            else if(i > 4 && x[i - 2] >= x[i - 4] && x[i] + x[i - 4] >= x[i - 2] &&
                    x[i - 1] <= x[i - 3] && x[i - 1] + x[i - 5]>=x[i - 3])
                return true;
        }
        return false;
    }
};