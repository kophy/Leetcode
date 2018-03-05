// version 1：map of map (memorize)
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode *root) {
        map<int, vector<vector<int>>> data;     // col -> (row -> val)
        dfs(data, root, 0, 0);
        
        vector<vector<int>> result;
        for (auto &p : data) {
            vector<int> temp;
            for (auto &v : p.second)
                temp.insert(temp.end(), v.begin(), v.end());
            result.push_back(temp);
        }
        return result;
    }
    
private:
    void dfs(map<int, vector<vector<int>>> &data, TreeNode *root, int row, int col) {
        if (!root)
            return;
        // map of map, some row doesn't exist
        while (data[col].size() <= row)
            data[col].push_back(vector<int>());
        data[col][row].push_back(root->val);
        
        dfs(data, root->left, row + 1, col - 1);
        dfs(data, root->right, row + 1, col + 1);
    }
};

// version 2: bfs
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode *root) {
        map<int, vector<int>> column_view;
        verticalSearch(column_view, root);
        vector<vector<int>> result;
        for (auto &p : column_view)
            result.push_back(p.second);
        return result;
    }

private:
    void verticalSearch(map<int, vector<int>> &column_view, TreeNode *root) {
        queue<tuple<TreeNode *, int>> data;
        if (root)
            data.push(make_tuple(root, 0));
        while (!data.empty()) {
            TreeNode *node = nullptr;
            int column = INT_MIN;
            tie(node, column) = data.front();
            data.pop();
            column_view[column].push_back(node->val);
            if (node->left)
                data.push(make_tuple(node->left, column - 1));
            if (node->right)
                data.push(make_tuple(node->right, column + 1));
        }
    }
};