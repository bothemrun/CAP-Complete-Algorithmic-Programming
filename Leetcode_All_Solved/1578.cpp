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
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();

        int time = 0;

        int left = 0;
        while(left<n){
            //window of same colors [left, right]
            int right = left;

            int win_max = neededTime[left];
            int win_sum = neededTime[left];

            while(right+1<n && colors[left] == colors[right+1] ){
                right++;

                win_max = max(win_max, neededTime[right] );
                win_sum += neededTime[right];
            }

            if(left != right){
                time += win_sum - win_max;
            }

            //update next
            left = right + 1;
        }

        return time;
    }
};
