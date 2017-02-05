class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[0] != 0)
            return false;

        stack<pair<int, int>> data;
        data.push(make_pair(0, 1));
        unordered_set<string> visited;
        visited.insert(make_state(0, 1));

        while (!data.empty()) {
            auto curr = data.top();
            data.pop();
            int pos = curr.first + curr.second, step = curr.second;
            if (pos == stones.back())
                return true;
            if (find(stones.begin(), stones.end(), pos) == stones.end())
                continue;
            int dstep[3] = {-1, 0, 1};
            for (int k = 0; k < 3; ++k) {
                if (step + dstep[k] <= 0)
                    continue;
                string state = make_state(pos, step + dstep[k]);
                if (visited.find(state) != visited.end())
                    continue;
                data.push(make_pair(pos, step + dstep[k]));
                visited.insert(state);
            }
        }
        return false;
    }

private:
    string make_state(int pos, int step) {
        return to_string(pos) + "@" + to_string(step);
    }
};