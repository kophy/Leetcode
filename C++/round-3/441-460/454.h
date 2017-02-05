class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> count;
        for (int a : A)
            for (int b : B)
                ++count[a + b];
        int result = 0;
        for (int c : C)
            for (int d : D)
                result += count[-(c + d)];
        return result;
    }
};