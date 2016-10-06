class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i <= min(n, 9); ++i)
            preorder_search(result, n, i);
        return result;
    }

private:
    void preorder_search(vector<int> &result, int n, int curr) {
        result.push_back(curr);
        curr *= 10;
        for (int i = 0; i < 10 && curr <= n; ++i)
            preorder_search(result, n, curr++);
    }
};