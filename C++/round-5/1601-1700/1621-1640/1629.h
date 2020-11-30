class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char result;
        int max_time = INT_MIN;
        for (int i = 0; i < keysPressed.size(); ++i) {
            int time = (i == 0)? releaseTimes[0] : (releaseTimes[i] - releaseTimes[i - 1]);
            if (time > max_time || (time == max_time && result < keysPressed[i])) {
                max_time = time;
                result = keysPressed[i];
            }
        }
        return result;
    }
};