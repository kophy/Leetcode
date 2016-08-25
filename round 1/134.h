class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.empty())
            return -1;
        int sum = 0;
        int min_sum = INT_MAX;
        int min_end = -1;

        for(int i = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            if(sum < min_sum) {
                min_sum = sum;
                min_end = i;
            }
        }
        if(sum < 0)
            return -1;
        else
            return (min_end + 1) % gas.size();
    }
};