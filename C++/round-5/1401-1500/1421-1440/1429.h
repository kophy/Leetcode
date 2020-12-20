class FirstUnique {
public:
  FirstUnique(vector<int> &nums) {
    index = 0;
    for (int num : nums) {
      add(num);
    }
  }

  int showFirstUnique() {
    if (unique_data.empty()) {
      return -1;
    }
    return unique_data.begin()->second;
  }

  void add(int value) {
    if (val_to_index.count(value)) {
      unique_data.erase(val_to_index[value]);
    } else {
      unique_data[index] = value;
      val_to_index[value] = index;
      ++index;
    }
  }

private:
  int index;
  map<int, int> unique_data;
  unordered_map<int, int> val_to_index;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */