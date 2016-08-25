class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        int n = citations.size();
        vector<int> count(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            if (citations[i] < n)
                ++count[citations[i]];
            else
                ++count[n];
        }
        int sum = 0;
        for (int j = n; j >= 0; --j) {
            sum += count[j];
            if (j <= sum)
                return j;
        }
        return 0;
    }
};