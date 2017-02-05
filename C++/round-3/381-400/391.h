class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int leftmost = INT_MAX, rightmost = INT_MIN;
        int downmost = INT_MAX, uppermost = INT_MIN;
        unordered_map<string, int> point_count;
        int area_sum = 0;

        // get four points of the large rectangle
        // add up area of each small rectangle
        for (auto rect : rectangles) {
            leftmost = min(leftmost, rect[0]);
            downmost = min(downmost, rect[1]);
            rightmost = max(rightmost, rect[2]);
            uppermost = max(uppermost, rect[3]);
            area_sum += (rect[2] - rect[0]) * (rect[3] - rect[1]);

            ++point_count[make_key(rect[0], rect[1])];
            ++point_count[make_key(rect[0], rect[3])];
            ++point_count[make_key(rect[2], rect[1])];
            ++point_count[make_key(rect[2], rect[3])];
        }

        // check 1: four points of large rectangle should appear only once
        if (++point_count[make_key(leftmost, downmost)] != 2)
            return false;
        if (++point_count[make_key(leftmost, uppermost)] != 2)
            return false;
        if (++point_count[make_key(rightmost, downmost)] != 2)
            return false;
        if (++point_count[make_key(rightmost, uppermost)] != 2)
            return false;

        // check 2: other points should appear even times
        for (auto iter = point_count.begin(); iter != point_count.end(); ++iter)
            if (iter->second != 2 && iter->second != 4)
                return false;

        // check 3: no hole or inside overlapping
        return area_sum == (rightmost - leftmost) * (uppermost - downmost);
    }

private:
    string make_key(int x, int y) {
        return to_string(x) + "@" + to_string(y);
    }
};