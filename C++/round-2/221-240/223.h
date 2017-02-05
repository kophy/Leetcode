class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int w = 0, h = 0;
        if (isOverlapped(A, B, C, D, E, F, G, H)) {
            w = min(C, G) - max(A, E);
            h = min(D, H) - max(B, F);
        }
        return (C - A) * (D - B) + (G - E) * (H - F) - w * h;
    }

private:
    bool isOverlapped(int A, int B, int C, int D, int E, int F, int G, int H) {
        return min(C, G) > max(A, E) && min(D, H) > max(B, F);
    }
};