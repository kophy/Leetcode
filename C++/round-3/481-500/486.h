class Solution {
public:
    bool PredictTheWinner(vector<int> &nums) {
        N = nums.size();
        sums = vector<int>(N + 1, 0);
        for (int i = 0; i < N; ++i)
            sums[i + 1] = sums[i] + nums[i];
        int sum = sums[N] - sums[0];
        return getMaxScores(nums, 0, (int)nums.size() - 1) >= sum / 2.0;
    }
    
private:
    int N;
    
    vector<int> sums;
    
    unordered_map<int, int> score;
    
    int makeKey(int b, int e) {
        return b * N + e;
    }
    
    int getMaxScores(vector<int> &nums, int b, int e) {
        if (b > e)
            return 0;
        if (b == e)
            return nums[b];
        int key = makeKey(b, e);
        if (score.find(key) != score.end())
            return score[key];
        int sum = sums[e + 1] - sums[b];
        int left = nums[b], right = nums[e];
        left += sum - getMaxScores(nums, b + 1, e);
        right += sum - getMaxScores(nums, b, e - 1);
        score[key] = max(left, right);
        return score[key];
    }
};