class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        dfs(result, n, 0);
        return result;
    }

private:
    void dfs(vector<int> &result, int n, int temp) {
        if (temp > n)
            return;
        if (temp > 0)
            result.push_back(temp);
        for (int i = 0; i < 10; ++i) {
            if (temp == 0 && i == 0)
                continue;
            dfs(result, n, temp * 10 + i);
        }
    }
};