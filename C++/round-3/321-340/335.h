class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        unordered_set<string> visited;
        visited.insert(make_key(0, 0));
        int i = 0, j = 0;
        int di[4] = {0, -1, 0, 1}, dj[4] = {1, 0, -1, 0};
        for (int k = 0; k < x.size(); ++k) {
            for (int d = 1; d <= x[k]; ++d) {
                i += di[k % 4];
                j += dj[k % 4];
                string key = make_key(i, j);
                if (visited.find(key) != visited.end())
                    return true;
                visited.insert(key);
            }
        }
        return false;
    }

private:
    string make_key(int i, int j) {
        return to_string(i) + "@" + to_string(j);
    }
};