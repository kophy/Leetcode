class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size());
        vector<int> behind;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int count = search(behind, nums[i]);
            result[i] = count;
            behind.insert(behind.begin() + count, nums[i]);
        }
        return result;
    }
private:
    int search(vector<int> &behind, int target) {
        int low = 0, high = behind.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (behind[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};