class Solution {
public:
    bool isReflected(vector<pair<int, int>> &points) {
        map<int, unordered_set<int>> data;
        for (auto &point : points)
            data[point.first].insert(point.second);
        if (data.size() <= 1)
            return true;
        
        // directly use minimum(x) and maximum(x), no need to find median
        int pivot = data.begin()->first + data.rbegin()->first;
        for (auto iter = data.begin(); iter != data.end(); ++iter) {
            unordered_set<int> &left = iter->second;
            unordered_set<int> &right = data[pivot - iter->first];
            if (left.size() != right.size())
                return false;
            for (int y : left)
                if (!right.count(y))
                    return false;
        }
        return true;
    }
};