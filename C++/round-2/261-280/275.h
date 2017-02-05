class Solution {
public:
    /*  I still can't understand or explain this binary search clearly.
    	In most cases, we try to shrink possible range [l, r] until it contains only one element;
    	but here the range's defintion is obscure.
    */
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        int l = 0, r = N - 1;
		
		// maybe should treat [l, r] as a black box part...
        while (l <= r) {
            int m = (l + r) / 2;
            if (citations[m] < N - m)
                l = m + 1;
            else if (citations[m] > N - m)
                r = m - 1;
            else
                return citations[m];
        }

		// use l because l is safe -- citation[l] >= N - l
        return N - l;
    }
};