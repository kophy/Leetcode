class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int newColor) {
    // If old color and new color are the same, there will be infinite loop.
    if (image[sr][sc] != newColor)
      floodFill(image, sr, sc, image[sr][sc], newColor);
    return image;
  }

 private:
  void floodFill(vector<vector<int>> &image, int sr, int sc, int oldColor,
                 int newColor) {
    int M = image.size(), N = image[0].size();
    image[sr][sc] = newColor;

    int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, -1, 0, 1};
    for (int k = 0; k < 4; ++k) {
      int nr = sr + dr[k], nc = sc + dc[k];
      if (nr >= 0 && nr < M && nc >= 0 && nc < N && image[nr][nc] == oldColor)
        floodFill(image, nr, nc, oldColor, newColor);
    }
  }
};
