// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int begin = 1;
        int end = n;
        while(begin < end && !isBadVersion(begin)) {
            int middle = begin + (end - begin) / 2;
            if (isBadVersion(middle))
                end = middle;
            else
                begin = middle + 1;
        }
        return begin;
    }
};