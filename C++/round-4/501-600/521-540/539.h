class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (string &timePoint : timePoints)
            minutes.push_back(toMinutes(timePoint));
        int min_diff = INT_MAX, M = 24 * 60;
        for (int i = 0; i < minutes.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = min((minutes[i] - minutes[j] + M) % M, (minutes[j] - minutes[i] + M) % M);
                min_diff = min(min_diff, diff);
            }
        }
        return min_diff;
    }
    
private:
    int toMinutes(string &timePoint) {
        int pos = timePoint.find(':');
        return stoi(timePoint.substr(0, pos)) * 60 + stoi(timePoint.substr(pos + 1));
    }
};