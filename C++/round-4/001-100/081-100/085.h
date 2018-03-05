class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int result = 0;
        vector<int> heights(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    ++heights[j];
            }
            result = max(result, largestRectangleArea(heights));
        }
        return result;
    }
    
private:
    int largestRectangleArea(vector<int> &heights) {
        heights.push_back(0);
        
        int result = 0;
        stack<int> data;
        for (int i = 0; i < heights.size(); ++i) {
            while (!data.empty() && heights[data.top()] >= heights[i]) {
                int h = heights[data.top()];
                data.pop();
                int w = data.empty()? i : (i - 1 - data.top());
                result = max(result, h * w);
            }
            data.push(i);
        }
        return result;
    }
};