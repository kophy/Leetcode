class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int N = nums.size();
        // find median for wiggle
        auto pmid = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(), pmid, nums.end());
        int mid = *pmid;

        // virtual indexing
        auto V = [&N](int i)->int {
            return (1 + 2 * (i)) % (N | 1);
        };

        // three way partition
        int i = 0, j = 0, k = N;
        while (j < k) {
            if (nums[V(j)] > mid)
                swap(nums[V(i++)], nums[V(j++)]);
            else if (nums[V(j)] < mid)
                swap(nums[V(j)], nums[V(--k)]);
            else
                ++j;
        }
    }
};