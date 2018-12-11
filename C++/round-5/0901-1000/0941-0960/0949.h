class Solution {
 public:
  string largestTimeFromDigits(vector<int> &A) {
    vector<int> largestTime;
    sort(A.begin(), A.end());
    while (true) {
      if (isValidTime(A)) {
        if (largestTime.empty() || compareTime(A, largestTime) > 0) {
          largestTime = A;
        }
      }
      if (!next_permutation(A.begin(), A.end())) {
        break;
      }
    }
    if (largestTime.empty()) {
      return "";
    }
    stringstream ss;
    ss << largestTime[0] << largestTime[1] << ":" << largestTime[2]
       << largestTime[3];
    return ss.str();
  }

 private:
  bool isValidTime(vector<int> &t) {
    int h = getHour(t);
    int m = getMinute(t);
    return h <= 23 && m <= 59;
  }

  int getHour(vector<int> &t) { return t[0] * 10 + t[1]; }

  int getMinute(vector<int> &t) { return t[2] * 10 + t[3]; }

  int compareTime(vector<int> &t1, vector<int> &t2) {
    int ts1 = getHour(t1) * 60 + getMinute(t1);
    int ts2 = getHour(t2) * 60 + getMinute(t2);
    return ts1 - ts2;
  }
};
