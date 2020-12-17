class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int result = k;
        for (int x : arr) {
            if (result < x) {
                break;
            } else {
                ++result;
            }
        }
        return result;
    }
};