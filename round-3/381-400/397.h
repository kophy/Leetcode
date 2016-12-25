/* shortest path: BFS */
class Solution {
public:
    int integerReplacement(int n) {
        queue<pair<long, int>> data;
        unordered_set<long> visited;
        data.push(make_pair((long)n, 0));
        visited.insert(n);

        while (!data.empty()) {
            auto temp = data.front();
            data.pop();
            if (temp.first == 1)
                return temp.second;
            long v = temp.first;    // avoid overflow
            if (v % 2 == 0) {
                if (visited.find(v / 2) != visited.end())
                    continue;
                data.push(make_pair(v / 2, temp.second + 1));
                visited.insert(v / 2);
            } else {
                if (visited.find(v + 1) == visited.end()) {
                    data.push(make_pair(v + 1, temp.second + 1));
                    visited.insert(v + 1);
                }
                if (visited.find(v - 1) == visited.end()) {
                    data.push(make_pair(v - 1, temp.second + 1));
                    visited.insert(v - 1);
                }
            }
        }
        return -1;
    }
};