class SummaryRanges {
public:
    SummaryRanges() {}

    void addNum(int val) {
        int low = 0, high = sum.size();
        while(low < high) {
            int mid = (low + high) / 2;
            if(sum[mid].start <= val)
                low = mid + 1;
            else
                high = mid;
        }
        int pivot = low;
        if(pivot == 0) {
            if(sum.size() && val == sum[0].start - 1)
                sum[0].start = val;
            else
                sum.insert(sum.begin(), Interval(val,val));
        } else if(pivot == sum.size()) {
            if(val == sum[pivot - 1].end + 1)
                sum[pivot - 1].end = val;
            else if(val > sum[pivot - 1].end + 1)
                sum.insert(sum.end(), Interval(val,val));
        } else {
            if(val <= sum[pivot - 1].end)
                return;
            if(sum[pivot - 1].end + 2 == sum[pivot].start) {
                sum[pivot - 1].end = sum[pivot].end;
                sum.erase(sum.begin() + pivot);
            } else if(val == sum[pivot - 1].end + 1)
                sum[pivot - 1].end = val;
            else if(val == sum[pivot].start - 1)
                sum[pivot].start = val;
            else
                sum.insert(sum.begin() + pivot, Interval(val,val));
        }
    }
    vector<Interval> getIntervals() {
        return sum;
    }

private:
    vector<Interval> sum;
};