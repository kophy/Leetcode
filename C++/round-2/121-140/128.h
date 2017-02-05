class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> sequence;

        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];

            /* skip same elements */
            if (sequence.find(n) != sequence.end())
                continue;

            /* find length of prev and next sequence */
            bool prev_exist = (sequence.find(n - 1) != sequence.end());
            bool next_exist = (sequence.find(n + 1) != sequence.end());
            int prev_length = prev_exist? sequence[n - 1] : 0;
            int next_length = next_exist? sequence[n + 1] : 0;

            int length = prev_length + 1 + next_length;
            sequence[n] = length;

            /* update length of prev and next sequence if applicable */

            // the trick is don't update all elements —— just leftmost and rightmost elements are enough!
            if (prev_exist)
                sequence[n - prev_length] = length;
            if (next_exist)
                sequence[n + next_length] = length;
        }

        /* find max sequence length */
        int result = 0;
        for (auto iter = sequence.begin(); iter != sequence.end(); ++iter)
            result = max(result, iter->second);
        return result;
    }
};