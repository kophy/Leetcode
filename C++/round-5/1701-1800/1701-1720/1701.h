class Solution {
 public:
  double averageWaitingTime(vector<vector<int>>& customers) {
    double total_wait_time = 0;
    int finish_time = 0;
    for (int i = 0; i < customers.size(); ++i) {
      int arrival_time = customers[i][0];
      int prepare_time = customers[i][1];

      finish_time = max(finish_time, arrival_time) + prepare_time;
      total_wait_time += finish_time - arrival_time;
    }
    return total_wait_time / customers.size();
  }
};