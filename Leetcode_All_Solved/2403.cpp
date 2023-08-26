//m0
//recursion with memo.  bitmask dp.

//we can pre-compute the popcount,
//but we just use gcc __builtin_popcount(),
//since we have c++ std popcount() only after C++20.

//gain has a fixed formula:
#define get_gain(killed) (1 + killed)

//ternary operator precedence is among the lowest.
#define division_ceil(a, b) ( (a/b) + ((a%b==0)? 0:1) ) 
// ( (a/b) + (a%b==0)? 0:1 )

#define notyet (-1)
#include<algorithm>
#include<limits.h>

class Solution {
public:
    int n;
    int max_mask;
    vector<long long> memo;

    long long enum_monster_to_kill(const vector<int>& power, const int& mask){

        if(mask == max_mask) return 0;

        if(memo[mask] != notyet) return memo[mask];


        int killed = __builtin_popcount(mask);
        int gain = get_gain(killed);

        long long min_day = LLONG_MAX;
        int mask1 = 1;

        for(int i=0;i<n;i++, mask1 <<= 1)if( (mask & mask1) == 0){

            long long need_days = division_ceil( power[i], gain );

            int new_mask = ( mask | mask1 );

            min_day = min(
                min_day,
                need_days + enum_monster_to_kill(power, new_mask)
            );
        }

        return memo[mask] = min_day;
    }

    long long minimumTime(vector<int>& power) {
        n = power.size();
        max_mask = (1 << n) - 1;

        memo.resize( max_mask + 1, notyet );
        return enum_monster_to_kill(power, 0);
    }
};
