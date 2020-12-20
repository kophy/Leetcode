class Solution {
public:
  vector<int> sortItems(int n, int m, vector<int> &group,
                        vector<vector<int>> &beforeItems) {
    unordered_map<int, int> item_to_group;
    unordered_map<int, unordered_set<int>> group_items;
    for (int i = 0; i < n; ++i) {
      if (group[i] != -1) {
        item_to_group[i] = group[i];
        group_items[group[i]].insert(i);
      } else {
        item_to_group[i] = m;
        group_items[m].insert(i);
        ++m;
      }
    }

    unordered_map<int, unordered_set<int>> before_groups;
    for (int i = 0; i < m; ++i) {
      before_groups[i] = {};
    }
    for (int i = 0; i < n; ++i) {
      for (int j : beforeItems[i]) {
        if (item_to_group[i] == item_to_group[j]) {
          continue;
        }
        before_groups[item_to_group[i]].insert(item_to_group[j]);
      }
    }
    vector<int> sorted_groups = topologicalSort(m, before_groups);
    if (sorted_groups.empty()) {
      return {};
    }

    vector<int> result;
    for (int g : sorted_groups) {
      if (group_items[g].empty()) {
        continue;
      }
      const auto &items = group_items[g];

      unordered_map<int, unordered_set<int>> before_items;
      for (int i : items) {
        before_items[i] = {};
        for (int j : beforeItems[i]) {
          if (items.count(j)) {
            before_items[i].insert(j);
          }
        }
      }
      vector<int> sorted_items = topologicalSort(items.size(), before_items);
      if (sorted_items.empty()) {
        return {};
      }
      result.insert(result.end(), sorted_items.begin(), sorted_items.end());
    }
    return result;
  }

private:
  vector<int>
  topologicalSort(int n, unordered_map<int, unordered_set<int>> &before_items) {
    unordered_map<int, unordered_set<int>> successors;
    unordered_map<int, int> precursor_count;

    for (const auto &p : before_items) {
      successors[p.first] = {};
      precursor_count[p.first] = 0;
    }

    for (const auto &p : before_items) {
      int i = p.first;
      for (int j : p.second) {
        successors[j].insert(i);
        ++precursor_count[i];
      }
    }

    vector<int> result;
    queue<int> data;
    for (const auto &p : precursor_count) {
      if (p.second == 0) {
        data.push(p.first);
      }
    }
    while (!data.empty()) {
      int i = data.front();
      data.pop();
      result.push_back(i);
      for (int j : successors[i]) {
        if (--precursor_count[j] == 0) {
          data.push(j);
        }
      }
    }

    if (result.size() < n) {
      return {};
    }
    return result;
  }
};