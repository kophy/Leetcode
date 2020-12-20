class Solution {
public:
  vector<int> deckRevealedIncreasing(vector<int> &deck) {
    vector<int> indices = revealIndices(deck.size());
    sort(deck.begin(), deck.end());
    vector<int> result(deck.size());
    for (int i = 0; i < indices.size(); ++i) {
      result[indices[i]] = deck[i];
    }
    return result;
  }

private:
  vector<int> revealIndices(int N) {
    vector<int> indices;
    deque<int> data;
    for (int i = 0; i < N; ++i) {
      data.push_back(i);
    }
    while (!data.empty()) {
      indices.push_back(data.front());
      data.pop_front();
      if (!data.empty()) {
        int temp = data.front();
        data.pop_front();
        data.push_back(temp);
      }
    }
    return indices;
  }
};
