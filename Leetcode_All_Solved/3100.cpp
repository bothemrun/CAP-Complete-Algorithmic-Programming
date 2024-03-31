class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int full = numBottles;
        int empty = 0;
        int exchange = numExchange;
        int drunk = 0;
        while( full != 0 || empty >= exchange ){
            //printf("full %d empty %d exchange %d drunk %d\n", full, empty, exchange, drunk);
            if(full != 0){
                drunk += full;
                empty += full;
                full = 0;
            }else{
                assert(empty >= exchange);
                empty -= exchange;
                full++;
                
                exchange++;
            }
        }
        //cout<<drunk<<endl<<endl;
        return drunk;
    }
};
