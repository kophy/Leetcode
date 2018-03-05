class Solution {
public:
	bool canAttendMeetings(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b)->bool {
			return a.start < b.start;
		});
		for (int i = 0; i < (int)intervals.size() - 1; ++i)
			if (intervals[i].end > intervals[i + 1].start)
				return false;
		return true;
	}
};