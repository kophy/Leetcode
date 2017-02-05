class Solution {
public:
    int hIndex(vector<int> &citations) {
        int N = citations.size();
        vector<int> count(N + 1, 0);
        for (int c : citations)
            ++count[min(c, N)];
        int sum = 0;
        for (int i = N; i >= 0; --i) {
            sum += count[i];
            /* make sure at least i papers have more than i citations */
			if (sum >= i)
                return i;
        }
        return 0;
    }
};