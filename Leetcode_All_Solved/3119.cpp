//O(nlogn)
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxPotholes(string road, int budget) {
        int n = road.size();

        vector<int> pots;
        int i=0;
        while(i<n){
            if(road[i] == '.'){
                i++;
                continue;
            }

            int j=i;
            while(j+1<n && road[j+1] == 'x'){
                j++;
            }

            pots.push_back(j - (i-1));

            //update
            i = j+1;
        }

        sort(pots.begin(), pots.end());

        int ans = 0;
        int p = (int)pots.size() - 1;
        for(;p>=0;p--){
            if(budget < pots[p] + 1) break;

            budget -= pots[p] + 1;

            ans += pots[p];
        }

        if(p>=0){
            assert(pots[p] >= 1);
            if(budget-1 >= 1) ans += budget - 1;
        }
        return ans;
    }
};
