// version 1: ordered set
class Solution {
public:
    int kEmptySlots(vector<int> &flowers, int k) {
        set<int> bloomed;
        for (int i = 0; i < flowers.size(); ++i) {
            int day = i + 1, x = flowers[i];
            auto it = bloomed.lower_bound(x);
            
            // closest flower right to current
            if (it != bloomed.end()) {
                if (*it - x == k + 1)
                    return day;
            }
            // closest flower left to current
            if (it != bloomed.begin()) {
                --it;
                if (x - *it == k + 1)
                    return day;
            }

            bloomed.insert(x);
        }
        return -1;
    }
};

// version 2: sliding window on space
class Solution {
public:
    int kEmptySlots(vector<int> &flowers, int k) {
        vector<int> days(flowers.size());
        for (int i = 0; i < flowers.size(); ++i)
            days[flowers[i] - 1] = i + 1;
        
        int begin = 0, end = k + 1, result = INT_MAX;
        
        // looking for a range days[begin:end] satisfying:
        // max(days[begin], days[end]) < min(days[begin+1:end-1])
        for (int i = 0; end < days.size(); ++i) {
            if (days[i] < days[begin] || days[i] <= days[end]) {   
                if (i == end)
                    result = min(result, max(days[begin], days[end])); // find earliest
                // slide window
                begin = i;
                end = k + 1 + i;
            }
        }
        return (result == INT_MAX)? -1 : result;
    }
};