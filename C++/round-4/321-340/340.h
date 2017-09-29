class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int result = 0, begin = 0, end = 0;
        unordered_map<int, int> count;
        for (; end < s.size(); ++end) {
            ++count[s[end]];
            while (count.size() > k) {
                if (--count[s[begin]] == 0)
                    count.erase(s[begin]);
                ++begin;
            }
            result = max(result, end - begin + 1);
        }
        return result;
    }
};