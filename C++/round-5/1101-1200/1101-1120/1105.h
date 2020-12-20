class Solution {
public:
  int minHeightShelves(vector<vector<int>> &books, int shelf_width) {
    vector<int> memo(books.size(), INT_MAX);
    return helper(books, shelf_width, memo, 0);
  }

private:
  int helper(vector<vector<int>> &books, int shelf_width, vector<int> &memo,
             int pos) {
    if (pos >= books.size()) {
      return 0;
    }
    if (memo[pos] != INT_MAX) {
      return memo[pos];
    }
    int width = 0, height = 0;
    for (int i = 0; pos + i < books.size(); ++i) {
      width += books[pos + i][0];
      if (width > shelf_width) {
        break;
      }
      height = std::max(height, books[pos + i][1]);
      memo[pos] = std::min(
          memo[pos], height + helper(books, shelf_width, memo, pos + i + 1));
    }
    return memo[pos];
  }
};
