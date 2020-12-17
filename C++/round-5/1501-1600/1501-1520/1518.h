class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = 0;
        while (numBottles >= numExchange) {
            int exchangedBottles = numBottles / numExchange;
            result += exchangedBottles * numExchange;
            numBottles -= exchangedBottles * numExchange;
            numBottles += exchangedBottles;
        }
        result += numBottles;
        return result;
    }
};