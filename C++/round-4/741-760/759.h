class Solution {
 public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>> &schedule) {
    vector<Interval> workTime = commonWorkTime(schedule);
    vector<Interval> freeTime;
    for (int i = 1; i < workTime.size(); ++i)
      freeTime.push_back(Interval(workTime[i - 1].end, workTime[i].start));
    return freeTime;
  }

 private:
  vector<Interval> commonWorkTime(vector<vector<Interval>> &schedule) {
    vector<Interval> intervals;
    for (auto &s : schedule)
      intervals.insert(intervals.end(), s.begin(), s.end());
    sort(intervals.begin(), intervals.end(),
         [](Interval &a, Interval &b) -> bool { return a.start < b.start; });

    vector<Interval> result;
    for (const Interval &interval : intervals) {
      if (result.empty() || result.back().end < interval.start)
        result.push_back(interval);
      else
        result.back().end = max(result.back().end, interval.end);
    }
    return result;
  }
};
