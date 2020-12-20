class Leaderboard {
public:
  Leaderboard() {}

  void addScore(int playerId, int score) {
    if (scores.count(playerId)) {
      if (--freqs[scores[playerId]] == 0) {
        freqs.erase(scores[playerId]);
      }
    }
    scores[playerId] += score;
    ++freqs[scores[playerId]];
  }

  int top(int K) {
    int result = 0;
    for (auto iter = freqs.rbegin(); iter != freqs.rend(); ++iter) {
      result += iter->first * min(iter->second, K);
      K -= iter->second;
      if (K <= 0) {
        break;
      }
    }
    return result;
  }

  void reset(int playerId) {
    if (--freqs[scores[playerId]] == 0) {
      freqs.erase(scores[playerId]);
    }
    scores[playerId] = 0;
    ++freqs[0];
  }

private:
  unordered_map<int, int> scores;
  map<int, int> freqs;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */