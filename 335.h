class Solution {
public:
    bool isSelfCrossing(vector<int>& steps) {
        set<pair<int, int>, pointcmp> visited;
        int x = 0, y = 0;
        visited.insert(makePair(x, y));

        for (int i = 0; i < steps.size(); ++i) {
            int direction = i % 4;
            for (int j = 0; j < steps[i]; ++j) {
                if (direction == 0)
                    ++y;
                if (direction == 1)
                    --x;
                if (direction == 2)
                    --y;
                if (direction == 3)
                    ++x;
                pair<int, int> temp = makePair(x, y);
                if (visited.find(temp) != visited.end())
                    return true;
                visited.insert(temp);
            }
        }
        return false;
    }
private:
    struct pointcmp {
        bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
            return a.first < b.first || (a.first == b.first && a.second < b.second);
        };
    };
    pair<int, int> makePair(int x, int y) {
        return pair<int, int>(x, y);
    }
};