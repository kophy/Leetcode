class Solution {
public:
    Solution(vector<int> nums) : data(nums) {}

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return data;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffled = data;
        int N = shuffled.size();
        for (int i = 0; i < N; ++i)
            swap(shuffled[i], shuffled[rand() % N]);
        return shuffled;
    }
private:
    vector<int> data;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */