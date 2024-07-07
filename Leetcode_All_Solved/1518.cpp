class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank = 0;
        int full = numBottles, empty = 0;
        int exchange = numExchange;

        while(full != 0){
            drank += full;
            empty += full;
            full = 0;

            full += empty/exchange;
            empty %= exchange;
        }
        return drank;
    }
};
