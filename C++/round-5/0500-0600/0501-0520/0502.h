class Solution {
 public:
  int findMaximizedCapital(int k, int W, vector<int> &Profits,
                           vector<int> &Capital) {
    // sort projects by capital in increasing order.
    vector<pair<int, int>> projects;
    for (int i = 0; i < Profits.size(); ++i) {
      projects.push_back(make_pair(Profits[i], Capital[i]));
    }
    sort(projects.begin(), projects.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
           return a.second < b.second;
         });
    auto cmp = [&projects](const int &a, const int &b) -> bool {
      return projects[a].first < projects[b].first;
    };
    priority_queue<int, vector<int>, decltype(cmp)> available_projects(cmp);
    for (int i = 0, j = 0; i < k; ++i) {
      // update the priority queue of available projects.
      while (j < projects.size() && projects[j].second <= W) {
        available_projects.push(j);
        ++j;
      }
      // choose the available project with largest profit.
      if (!available_projects.empty()) {
        int chosen_idx = available_projects.top();
        available_projects.pop();
        W += projects[chosen_idx].first;
      }
    }
    return W;
  }
};
