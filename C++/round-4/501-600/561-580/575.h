class Solution {
public:
    int distributeCandies(vector<int> &candies) {
        unordered_set<int> kinds(candies.begin(), candies.end());
        return min(kinds.size(), candies.size() / 2);
    }
};