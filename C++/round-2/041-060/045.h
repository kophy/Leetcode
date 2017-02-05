class Solution {
public:
    int jump(vector<int>& nums) {
        int max_reach = 0;
        int step = 0;
        int visited = 0;

        /* a simple BFS */
        while (max_reach < nums.size() - 1) {
            int max_reach_next = 0;
            for (int i = visited; i <= max_reach; ++i)
                max_reach_next = max(max_reach_next, i + nums[i]);
            ++step;
            visited = max_reach + 1;
            max_reach = max_reach_next;
        }

        return step;
    }
};