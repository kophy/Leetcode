class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        if (nums.size() == 0)
            return vector<int>();
        int N = nums.size();
        vector<int> result(N, 0);
        vector<int> sorted;

        for (int i = N - 1; i >= 0; --i) {
            int pivot = findLowerBound(sorted, nums[i]);
            result[i] = pivot;
            sorted.insert(sorted.begin() + pivot, nums[i]);
        }

        return result;
    }

private:
    int findLowerBound(vector<int> &data, int val) {
        int l = 0, h = data.size();
        while (l < h) {
            int m = l + (h - l) / 2;
            if (data[m] < val)
                l = m + 1;
            else
                h = m;
        }
        return l;
    }
};