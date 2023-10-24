//m0
//O(nlogn) sorting
//greed heap causes TLE

#define mod ((long long)1e9 + 7)
#define arithmetic_progression(x, y) ( (long long)(x+y) * (long long)(y - (x-1)) / 2 )

#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        auto cmp = [](const int& a, const int& b){
            return a>b;
        };
        sort(inventory.begin(), inventory.end(), cmp);

        int real_n = inventory.size();
        //dummy
        inventory.push_back(0);


        long long ans = 0;
        long long remain_balls = orders;
        long long i=0;
        while(i<real_n){
            while(i+1<real_n && inventory[i] == inventory[i+1] ){
                i++;
            }

            long long ball_cnt = (i+1) * (
                inventory[i] - inventory[i+1]
            );

            if(ball_cnt >= remain_balls) break;

            //take the full band
            remain_balls -= ball_cnt;

            ans = (
                ans +
                (i+1) *
                arithmetic_progression(
                    inventory[i+1] + 1,
                    inventory[i]
                )
            )%mod;

            //update
            i++;
        }


        //take full strips
        long long strip_width = i+1;
        long long full_height = remain_balls / strip_width;
        ans = (
            ans +
            strip_width *
            arithmetic_progression(
                inventory[i] - full_height+1,
                inventory[i]
            )
        )%mod;

        //take a partial strip
        remain_balls %= strip_width;
        ans = (
            ans +
            remain_balls *
            (inventory[i] - full_height)
        )%mod;

        return ans;
    }
};
