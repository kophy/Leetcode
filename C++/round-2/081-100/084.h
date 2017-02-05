class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);

        /*******************************************************************
        	Need more consideration. Currently I can't expalin it clearly.
        *******************************************************************/
        stack<int> left;

        int max_area = 0;

        for (int i = 0; i < heights.size(); ++i) {
            while (!left.empty() && heights[left.top()] >= heights[i]) {
                int h = heights[left.top()];
                left.pop();
                int w = (left.empty())? i : i - left.top() - 1;
                max_area = max(max_area, h * w);
            }
            left.push(i);
        }

        return max_area;
    }
};