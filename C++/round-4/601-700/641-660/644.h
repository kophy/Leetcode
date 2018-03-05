class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double eps = pow(10, -5);
        double l = *min_element(nums.begin(), nums.end());
        double r = *max_element(nums.begin(), nums.end());
        while (l + eps < r) {
            double m = (l + r) / 2;
            if (existsLargerAverage(nums, m, k))
                l = m;
            else
                r = m;
        }
        return l;
    }
    
private:
    bool existsLargerAverage(vector<int>& nums, double m, int k){
        double sum = 0, prev_sum = 0, min_prev_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i] - m;
            if (i >= k) {
                prev_sum += nums[i - k] - m;                        
                min_prev_sum = min(min_prev_sum, prev_sum); 
            }
            if(i >= k - 1)
                if (sum > min_prev_sum)
                    return true;
        }
        return false;                
    }
};