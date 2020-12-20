class TimeMap {
public:
  /** Initialize your data structure here. */
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    data[key][timestamp] = value;
  }

  string get(string key, int timestamp) {
    if (!data.count(key)) {
      return "";
    }
    auto iter = data[key].upper_bound(timestamp);
    if (iter == data[key].begin()) {
      return "";
    }
    return prev(iter)->second;
  }

private:
  unordered_map<string, map<int, string>> data;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
