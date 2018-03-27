class Solution {
 public:
  int uniqueMorseRepresentations(vector<string> &words) {
    unordered_set<string> morse_reprs;
    for (auto &word : words) {
      morse_reprs.insert(getMorseRepr(word));
    }
    return morse_reprs.size();
  }

 private:
  string getMorseRepr(string &s) {
    static string morse[] = {
        ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
        ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
        "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};
    stringstream ss;
    for (char c : s) {
      ss << morse[c - 'a'];
    }
    return ss.str();
  }
};
