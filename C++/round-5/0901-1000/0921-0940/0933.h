class RecentCounter {
 public:
  RecentCounter() {}

  int ping(int t) {
    while (!times.empty() && times.front() + 3000 < t) {
      times.pop_front();
    }
    times.push_back(t);
    return times.size();
  }

 private:
  deque<int> times;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
