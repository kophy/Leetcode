class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones.size() < 2)
            return true;
        if (stones[0] != 0)
            return false;

        unordered_set<int> reachable;
        for (auto stone : stones)
            reachable.insert(stone);

        stack<pair<int, int>> data;
        data.push(make_pair(0, 1));

        set<string> visited;
        visited.insert("0@1");

        int target = stones.back();
        while (!data.empty()) {
            auto p = data.top();
            data.pop();
            int pos = p.first + p.second;
            if (pos == target)
                return true;
            if (reachable.find(pos) != reachable.end()) {
                if (p.second > 1)
                    check_and_push(data, pos, p.second - 1, visited);
                check_and_push(data, pos, p.second, visited);
                check_and_push(data, pos, p.second + 1, visited);
            }
        }

        return false;
    }

private:
    void check_and_push(stack<pair<int, int>> &data, int pos, int step, set<string> &visited) {
        string key = to_string(pos) + "@" + to_string(step);
        if (visited.find(key) != visited.end())
            return;
        data.push(make_pair(pos, step));
        visited.insert(key);
    }
};