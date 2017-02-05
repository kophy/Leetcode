class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        int count[N + 1] = {0};
        for (int i = 0; i < citations.size(); ++i)
            ++count[min(citations[i], N)];

        int sum = 0;
        for (int h = N; h >= 0; --h) {
            sum += count[h];
            // h papers' citation >= h
            // (N-h) papers' citation <= h
            if (h <= sum)
                return h;
        }
        return 0;
    }
};