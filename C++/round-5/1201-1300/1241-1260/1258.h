class Solution {
public:
  vector<string> generateSentences(vector<vector<string>> &synonyms,
                                   string text) {
    unordered_map<string, int> word_to_index;
    int index = 0;
    for (const auto &p : synonyms) {
      for (const string &word : p) {
        if (word_to_index.count(word)) {
          continue;
        }
        word_to_index[word] = index++;
      }
    }
    vector<int> labels(word_to_index.size(), 0);
    for (int i = 0; i < labels.size(); ++i) {
      labels[i] = i;
    }
    for (const auto &p : synonyms) {
      unionLabels(labels, word_to_index[p[0]], word_to_index[p[1]]);
    }

    text.push_back(' ');
    vector<string> words;
    int begin = 0;
    for (int i = 0; i <= text.size(); ++i) {
      if (text[i] == ' ') {
        string word = text.substr(begin, i - begin);
        words.push_back(word);
        begin = i + 1;
      }
    }

    vector<string> result = {""};
    for (string &word : words) {
      vector<string> candidates;
      if (word_to_index.count(word)) {
        for (const auto &p : word_to_index) {
          if (findLabel(labels, word_to_index[word]) ==
              findLabel(labels, p.second)) {
            candidates.push_back(p.first);
          }
        }
      } else {
        candidates = {word};
      }

      vector<string> temp;
      for (string &candidate : candidates) {
        for (string &prefix : result) {
          if (prefix == "") {
            temp.push_back(candidate);
          } else {
            temp.push_back(prefix + " " + candidate);
          }
        }
      }
      result = temp;
    }
    sort(result.begin(), result.end());
    return result;
  }

private:
  void unionLabels(vector<int> &labels, int i, int j) {
    labels[findLabel(labels, i)] = findLabel(labels, j);
  }

  int findLabel(vector<int> &labels, int i) {
    if (labels[i] != i) {
      labels[i] = findLabel(labels, labels[i]);
    }
    return labels[i];
  }
};