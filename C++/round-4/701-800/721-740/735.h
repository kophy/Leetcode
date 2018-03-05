class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (int asteroid : asteroids) {
            // right-flying asteroid is always allowed
            if (asteroid > 0)
                result.push_back(asteroid);
            else {
                // cancel all left-flying asteroid with smaller weight
                while (!result.empty() && result.back() > 0 && result.back() < abs(asteroid))
                    result.pop_back();
                // check whether there is a right-flying asteroid with larger weight
                if (!result.empty() && result.back() > 0) {
                    if (result.back() == abs(asteroid))
                        result.pop_back();
                } else
                    result.push_back(asteroid);
            }
        }
        return result;
    }
};