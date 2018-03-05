class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = 0;
        int start = 0, end = 0; // keep range of consecutive zeros
        for (int i = 0; i <= flowerbed.size(); ++i) {
            if (i == flowerbed.size() || flowerbed[i] == 1) {
                end = i;
                int range = end - start;
                
                // bounds number: 0 / 1 /2
                if (start == 0 && end == flowerbed.size()) {
                    m += (range + 1) / 2;
                } else if (start == 0 || end == flowerbed.size()) {
                    m += range / 2;
                } else {
                    m += (range - 1) / 2;
                }
                start = i + 1;
            }
        }
        return m >= n;
    }
};