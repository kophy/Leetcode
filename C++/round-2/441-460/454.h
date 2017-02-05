class Solution {
public:
    /* extended version 2sum */
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> half;
        for (int a : A)
            for (int b : B)
                ++half[a + b];
        int count = 0;
        for (int c : C)
            for (int d : D)
                if (half.count(-(c + d)))
                    count += half[-(c + d)];
        return count;
    }
};