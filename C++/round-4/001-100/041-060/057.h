class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		auto first = intervals.begin(), last = intervals.end();
		while (first != intervals.end() && first->end < newInterval.start)
			++first;

		// pivot points to newInterval in intervals
		auto pivot = intervals.insert(first, newInterval);

		for (last = pivot + 1; last != intervals.end(); ++last) {
			if (last->start > pivot->end)
				break;
			else {
				pivot->start = min(pivot->start, last->start);
				pivot->end = max(pivot->end, last->end);
			}
		}
		intervals.erase(pivot + 1, last);
		return intervals;
	}
};