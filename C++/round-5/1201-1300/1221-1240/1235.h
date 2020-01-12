class Solution {
 public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                    vector<int>& profit) {
    vector<vector<int>> jobs;
    for (int i = 0; i < startTime.size(); ++i) {
      jobs.push_back({startTime[i], endTime[i], profit[i]});
    }
    sort(jobs.begin(), jobs.end(),
         [](const vector<int>& j1, const vector<int>& j2) -> bool {
           return j1[1] < j2[1];
         });
    int result = 0;
    map<int, int> dp;  // end time -> max profit
    dp[0] = 0;
    for (const auto& job : jobs) {
      auto iter = --dp.upper_bound(job[0]);
      if (iter->second + job[2] > dp.rbegin()->second) {
        dp[job[1]] = iter->second + job[2];
      }
    }
    return dp.rbegin()->second;
  }
};