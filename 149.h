/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int result = 0;
        for(int i = 0; i < points.size(); i++) {
            int same_point = 1;
            map<double, int> count;
            for(int j = i + 1; j < points.size(); j++) {
                if(points[i].x == points[j].x && points[i].y == points[j].y)
                    ++same_point;
                else if(points[i].x == points[j].x)
                    ++count[INT_MAX];
                else {
                    double slope = double(points[i].y - points[j].y) /
                                   double(points[i].x - points[j].x);
                    ++count[slope];
                }
            }
            int local_max = 0;
            for(auto iter = count.begin(); iter != count.end(); ++iter)
                local_max = max(local_max, iter->second);
            result = max(result, local_max + same_point);
        }
        return result;
    }
};