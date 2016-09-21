class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> count;
        for (int i = 0; i < nums.size(); ++i)
            ++count[nums[i]];

        // maintain a max heap if we want to push all elements into heap
        // maintain a min heap if we want to push only k elements into heap, and use top() as the gate keeper
        auto cmp = [&count](int &m, int &n)->bool {
            return count[m] > count[n];
        };
        priority_queue<int, vector<int>, decltype(cmp)> data(cmp);

        for (auto iter = count.begin(); iter != count.end(); ++iter) {
            if (data.size() < k)
                data.push(iter->first);
            else if (count[data.top()] < iter->second) {
                data.pop();
                data.push(iter->first);
            }
        }
        vector<int> result;
        for (int i = 0; i < k && !data.empty(); ++i) {
            result.push_back(data.top());
            data.pop();
        }
        return result;
    }
};