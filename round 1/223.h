class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int h = min(D, H) > max(B, F)? min(D, H) - max(B, F) : 0;
        int w = min(G, C) > max(A, E)? min(G, C) - max(A, E) : 0;
        return (D - B) * (C - A) + (H - F) * (G - E) - h * w;
    }
};