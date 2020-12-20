/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
public:
  vector<string> crawl(string startUrl, HtmlParser htmlParser) {
    queue<string> urls;
    urls.push(startUrl);
    unordered_set<string> seen;
    seen.insert(startUrl);

    string host = getHost(startUrl);
    while (!urls.empty()) {
      string curr = urls.front();
      urls.pop();
      for (string url : htmlParser.getUrls(curr)) {
        if (seen.count(url) || getHost(url) != host) {
          continue;
        }
        urls.push(url);
        seen.insert(url);
      }
    }
    return vector<string>(seen.begin(), seen.end());
  }

private:
  string getHost(string &url) {
    int i = url.find("//");
    int j = url.find("/", i + 2);
    if (j == string::npos) {
      return url.substr(i + 2);
    }
    return url.substr(i + 2, j - i - 2);
  }
};