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
        int max_points = 0;
        for (int i = 0; i < points.size(); ++i) {
            int same = 0, vertical = 0;
            map<double, int> slope_count;

            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y)
                    ++same;
                else if (points[i].x == points[j].x)
                    ++vertical;
                else
                    ++slope_count[slope(points[i], points[j])];
            }
            int local_max = same + vertical + 1;
            for (auto iter = slope_count.begin(); iter != slope_count.end(); ++iter)
                local_max = max(local_max, same + iter->second + 1);
            max_points = max(max_points, local_max);
        }

        return max_points;
    }

private:
    double slope(Point &p1, Point &p2) {
        return double(p1.y - p2.y) / double(p1.x - p2.x);
    }
};