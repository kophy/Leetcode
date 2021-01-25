class Solution {
 public:
  int largestAltitude(vector<int>& gain) {
    int largest_altitude = 0, current_altitude = 0;
    for (int x : gain) {
      current_altitude += x;
      largest_altitude = max(largest_altitude, current_altitude);
    }
    return largest_altitude;
  }
};