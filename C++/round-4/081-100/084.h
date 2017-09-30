class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        heights.push_back(0);
        
        int result = 0;
        stack<int> data;
        for (int i = 0; i < heights.size(); ++i) {
            while (!data.empty() && heights[data.top()] >= heights[i]) {
                int h = heights[data.top()];
                data.pop();
                
                // (i - 1) - (data.top() + 1) + 1 = i - 1 - data.top()
                int w = data.empty()? i : (i - 1 - data.top());
                result = max(result, h * w);
            }
            data.push(i);
        }
        return result;
    }
};