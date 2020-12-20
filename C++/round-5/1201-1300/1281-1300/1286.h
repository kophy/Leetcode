class CombinationIterator {
public:
  CombinationIterator(string characters, int combinationLength) {
    characters_ = characters;
    current_ = characters.substr(0, combinationLength);
    length_ = combinationLength;
  }

  string next() {
    string result = current_;
    int i = length_ - 1;
    for (; i >= 0; --i) {
      // Find the first i that current_[i:] can be updated.
      char c = current_[i];
      int position =
          find(characters_.begin(), characters_.end(), c) - characters_.begin();
      if (characters_.size() - position >= length_ - i + 1) {
        for (int j = 0; j < length_ - i; ++j) {
          current_[i + j] = characters_[position + j + 1];
        }
        break;
      }
    }
    if (i < 0) {
      current_ = "";
    }
    return result;
  }

  bool hasNext() { return (current_ != ""); }

private:
  string characters_;
  string current_;
  int length_;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters,
 * combinationLength); string param_1 = obj->next(); bool param_2 =
 * obj->hasNext();
 */