class Solution {
public:
  vector<int> prisonAfterNDays(vector<int> &cells, int N) {
    vector<vector<int>> results;
    unordered_map<string, int> pattern_to_day;
    pattern_to_day[makePattern(cells)] = N;

    while (N > 0) {
      simulateOneDay(cells);
      --N;
      string pattern = makePattern(cells);
      if (pattern_to_day.count(pattern)) {
        int T = pattern_to_day[pattern] - N;
        N %= T;
      } else {
        results.push_back(cells);
        pattern_to_day[pattern] = N;
      }
    }
    return cells;
  }

private:
  string makePattern(vector<int> &cells) {
    stringstream ss;
    for (int cell : cells) {
      ss << cell;
    }
    return ss.str();
  }

  void simulateOneDay(vector<int> &cells) {
    for (int i = 1; i < (int)cells.size() - 1; ++i) {
      if ((cells[i - 1] & 1) == (cells[i + 1] & 1)) {
        cells[i] |= 2;
      }
    }
    for (int i = 0; i < cells.size(); ++i) {
      cells[i] >>= 1;
    }
  }
};
