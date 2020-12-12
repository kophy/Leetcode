class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        for (int i = nodes - 1; i > 0; --i) {
            value[parent[i]] += value[i];
        }
        
        int result = 1;
        for (int i = 1; i < nodes; ++i) {
            if (value[parent[i]] == 0 || value[i] == 0) {
                value[i] = 0;
            } else {
                ++result;
            }
        }
        return (value[0] == 0)? 0 : result;
    }
};

class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<vector<int>> children(nodes);
        for (int i = 0; i < nodes; ++i) {
            if (parent[i] >= 0) {
                children[parent[i]].push_back(i);
            }
        }
        return helper(children, value, 0).second;
    }
    
private:
    pair<int, int> helper(vector<vector<int>> &children, vector<int> &value, int i) {        
        int sum = value[i];
        int count = 1;
        for (int j : children[i]) {
            auto p = helper(children, value, j);
            sum += p.first;
            count += p.second;
        }
        return (sum == 0)? std::make_pair(0, 0) : std::make_pair(sum, count);
    }
};