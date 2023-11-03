//(n)

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
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();

        int last1to0 = 0;
        for(;last1to0<n;last1to0++)
            if(seats[last1to0] == 1) break;

        int first1 = last1to0;
        while(last1to0 + 1<n && seats[last1to0 + 1] == 1){
            last1to0++;
        }

        
        int max_dist = 0;
        for(int i=last1to0 + 1;i+1<n;i++){
            if(seats[i]==0 && seats[i+1]==1){
                //from 0 to 1
                max_dist = max(
                    max_dist,
                    ( (i+1) - last1to0 ) / 2
                );
            }else if(seats[i]==1 && seats[i+1]==0){
                last1to0 = i;
            }
        }

        
        //edge case
        max_dist = max(
            max_dist,
            first1
        );
        int last1 = n-1;
        for(;last1>=0;last1--)
            if(seats[last1] == 1) break;
        
        max_dist = max(
            max_dist,
            (n-1) - last1
        );

        return max_dist;
    }
};
