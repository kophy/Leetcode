/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
  vector<Interval> intervalIntersection(vector<Interval> &A,
                                        vector<Interval> &B) {
    vector<Interval> result;
    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
      if (A[i].end < B[j].start) {
        ++i;
      } else if (B[j].end < A[i].start) {
        ++j;
      } else if (A[i].end < B[j].end) {
        result.push_back(Interval(max(A[i].start, B[j].start), A[i].end));
        ++i;
      } else {
        result.push_back(Interval(max(A[i].start, B[j].start), B[j].end));
        ++j;
      }
    }
    return result;
  }
};
