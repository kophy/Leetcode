class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int l = 0, r = len - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (citations[m] >= len - m)
                r = m - 1;
            else
                l = m + 1;
        }
        return len - l;
    }
};