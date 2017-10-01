class Solution {
public:
    int removeBoxes(vector<int> &boxes) {
        return helper(boxes, 0, (int)boxes.size() - 1, 0);
    }
    
private:
    int cache[100][100][100] = {0};
    
    int helper(vector<int> &boxes, int l, int r, int k) {
        if (l > r)
            return 0;
        if (cache[l][r][k] > 0)
            return cache[l][r][k];
        
        int result = (k + 1) * (k + 1) + helper(boxes, l, r - 1, 0);
        for (int i = l; i < r; ++i) {
            if (boxes[i] == boxes[r])
                result = max(result, helper(boxes, l, i, k + 1) + helper(boxes, i + 1, r - 1, 0));
        }
        
        cache[l][r][k] = result;
        return result;
    }
};