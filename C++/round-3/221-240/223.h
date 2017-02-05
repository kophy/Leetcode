class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A, E), right = min(C, G);
        int bottom = max(B, F), top = min(D, H);
        int result = (C - A) * (D - B) + (G - E) * (H - F);
        if (left < right && bottom < top)
            result -= (right - left) * (top - bottom);
        return result;
    }
};