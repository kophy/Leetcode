class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        heights.push_back(0);
        stack<int> index;

        for(int i = 0; i < heights.size(); i++) {
            while(!index.empty() && heights[index.top()] >= heights[i]) {
                int h = heights[index.top()];
                index.pop();
                int sidx = index.empty() ? -1 : index.top();
                max_area = max(max_area, h * (i-sidx-1));
            }
            index.push(i);
        }
        return max_area;
    }
};