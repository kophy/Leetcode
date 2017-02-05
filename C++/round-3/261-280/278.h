// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1, e = n;
        while (s < e) {
            int m = s + (e - s) / 2;
            if (!isBadVersion(m))
                s = m + 1;
            else
                e = m;
        }
        return s;
    }
};