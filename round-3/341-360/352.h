class SummaryRanges {
public:
    SummaryRanges() {}

    void addNum(int val) {
        int pivot = findPivot(val);
        // case 1: first element
        if (pivot == 0) {
            // case 1.1: merge with first interval
            if (data.size() && data[0].start <= val + 1)
                data[0].start = min(data[0].start, val);
            // case 1.2: add new interval
            else
                data.insert(data.begin(), Interval(val, val));
        }
        // case 2: last element
        else if (pivot == data.size()) {
            // case 2.1: merge with last interval
            if (data[pivot - 1].end + 1 >= val)
                data[pivot - 1].end = max(data[pivot - 1].end, val);
            // case 2.2: add new interval
            else
                data.insert(data.end(), Interval(val, val));
        }
        // case 3: middle element
        else {
            // case 3.1: merge with interval before, with interval after if required
            if (data[pivot - 1].end + 1 >= val) {
                data[pivot - 1].end = max(data[pivot - 1].end, val);
                if (data[pivot - 1].end + 1 >= data[pivot].start) {
                    data[pivot - 1].end = max(data[pivot - 1].end, data[pivot].end);
                    data.erase(data.begin() + pivot);
                }
            }
            // case 3.2: merge with interval after
            else if (data[pivot].start <= val + 1)
                data[pivot].start = min(data[pivot].start, val);
            // case 3.3: add new interval
            else
                data.insert(data.begin() + pivot, Interval(val, val));
        }
    }
    
    vector<Interval> getIntervals() {
        return data;
    }

private:
    vector<Interval> data;
    
    int findPivot(int val) {
        int l = 0, h = data.size();
        while (l < h) {
            int m = l + (h - l) / 2;
            if (data[m].start < val)
                l = m + 1;
            else
                h = m;
        }
        return l;
    }
};