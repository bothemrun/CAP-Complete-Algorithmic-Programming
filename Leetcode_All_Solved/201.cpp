class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long ans = 0;
        long long mask = (long long)1 << 31;

        for(int i=31;i>=0;i--){
            //cout << mask << endl;

            long long l_bit = left & mask;
            long long r_bit = right & mask;
            if(l_bit && r_bit) ans += l_bit;
            if(!l_bit && r_bit){
                break;
            }

            mask >>= 1;
        }
        return (int)ans;
    }
};
