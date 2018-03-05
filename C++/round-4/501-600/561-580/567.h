class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(26, 0);
        for (char c : s1)
            ++count[c - 'a'];
        
        int k = s1.size();
        for (int i = 0; i < s2.size(); ++i) {
            char c = s2[i];
            --count[c - 'a'];
            if (i >= k)
                ++count[s2[i - k] - 'a'];
            if (i >= k - 1 && allZero(count))
                return true;
        }
        return false;
    }
    
private:
    bool allZero(vector<int> &nums) {
        for (int num : nums)
            if (num != 0)
                return false;
        return true;
    }
};