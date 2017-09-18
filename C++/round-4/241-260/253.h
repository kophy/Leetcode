class Solution {
public:
	int minMeetingRooms(vector<Interval> &intervals) {
		map<int, int> time2diff;
		for (auto &interval : intervals) {
			++time2diff[interval.start];
			--time2diff[interval.end];
		}
		int current_room = 0, max_room = 0;
		for (auto iter = time2diff.begin(); iter != time2diff.end(); ++iter) {
			current_room += iter->second;
			max_room = max(max_room, current_room);
		}
		return max_room;
	}
};