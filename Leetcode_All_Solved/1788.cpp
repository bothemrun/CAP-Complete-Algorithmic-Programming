//O(n)
//prefix sum of only non-negative,

#define range_sum(i, j) ( (i-1>=0)? ( prefix[j] - prefix[i-1] ):prefix[j] )
#define clip(x, c) ( max(x, c) )

#include<unordered_map>
#include<limits.h>
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
    int maximumBeauty(vector<int>& flowers) {
        int n = flowers.size();

        unordered_map<int, vector<int>> f2i;
        for(int i=0;i<n;i++) f2i[ flowers[i] ].push_back(i);

        for(auto it=f2i.begin(); it != f2i.end();){
            if(it->second.size() >= 2) it++;
            else it = f2i.erase(it);
        }


        //no overflow
        vector<int> prefix(n);
        prefix.front() = clip( flowers.front(), 0 );
        for(int i=1;i<n;i++)
            prefix[i] = prefix[i-1] + clip( flowers[i], 0 );
        
        
        int max_sum = INT_MIN;
        for(const auto& [key, val]: f2i){
            int i = val.front(), j = val.back();
            int sum = range_sum(i, j);

            if(key < 0) sum += 2 * key;

            max_sum = max(max_sum, sum);
        }

        return max_sum;
    }
};
