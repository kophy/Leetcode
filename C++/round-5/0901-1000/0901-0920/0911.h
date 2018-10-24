class TopVotedCandidate {
 public:
  TopVotedCandidate(vector<int> persons, vector<int> times) {
    vector<int> count(persons.size(), 0);
    int winner = 0;
    for (int i = 0; i < times.size(); ++i) {
      ++count[persons[i]];
      if (count[persons[i]] >= count[winner]) {
        winner = persons[i];
      }
      time2winner[times[i]] = winner;
    }
  }

  int q(int t) {
    // find the largest timestamp before t.
    auto iter = time2winner.upper_bound(t);
    --iter;
    return iter->second;
  }

 private:
  map<int, int> time2winner;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
