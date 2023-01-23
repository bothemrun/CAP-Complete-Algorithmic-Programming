#define test 0 //1 0

#if test == 1
inline void print_binary(uint32_t x, const string& message=""){
    vector<bool> result(32);
    for(int i=0;i<32;i++){
        result[i] = x & 1;
        x >>= 1;
    }
    
    for(int i=31;i>=0;i--){
        cout << result[i];
        if(i%4 == 0) cout << " ";
    }
    cout << " " << message << endl;
}
#endif

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t low = 1;
        uint32_t high = 1 << 31;
        uint32_t low_inv = ~low;
        uint32_t high_inv = ~high;
        for(int i=0;i<16;i++){
            uint32_t bit_low = (n & low) == low;
            uint32_t bit_high = (n & high) == high;

            #if test == 1
            print_binary(n, "last n");
            #endif

            //NOTE: n &= (low_inv | high_inv);
            n &= low_inv;
            n &= high_inv;

            #if test == 1
            print_binary(n, "&=");
            #endif
            
            n |= (bit_low * high) | (bit_high * low);

            #if test == 1
            print_binary(n, "|=");
            #endif

            low <<= 1;
            high >>= 1;

            //NOTE: for unsigned, pad by 0
            //low_inv <<= 1;
            //high_inv >>= 1;
            low_inv = ~low;
            high_inv = ~high;
            
            #if test == 1
            print_binary(low, "low");
            print_binary(low_inv, "low_inv");
            print_binary(high, "high");
            print_binary(high_inv, "high_inv");
            cout << endl;
            #endif
        }

        return n;
    }
};
