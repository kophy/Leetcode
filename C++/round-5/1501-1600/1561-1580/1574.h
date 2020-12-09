class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int N = arr.size();

        int first = 0;
        while (first + 1 < arr.size() && arr[first] <= arr[first + 1]) {
            ++first;
        }
        if (first == arr.size() - 1) {
            return 0;
        }
        int result = N - first - 1;
        
        map<int, int> val_to_index;
        val_to_index[arr[N - 1]] = N - 1;
        for (int i = N - 2; i >= 0; --i) {
            if (arr[i] > arr[i + 1]) {
                break;
            }
            val_to_index[arr[i]] = i;
            result = min(result, i);
        }
        
        for (int i = 0; i  <= first; ++i) {
            auto iter = val_to_index.lower_bound(arr[i]);
            if (iter == val_to_index.end()) {
                result = min(result, N - i - 1);
            } else {
                result = min(result, iter->second - i - 1);
            }
        }
        return result;
    }
};