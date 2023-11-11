//m0
//Thinking Process

//[A] Greedy Proof
//1. for 2 arrays, how to pair them so the sum of pair products is maxmized?
//2. let a <= b, x <= y
//3. ax + by ? ay + bx
//4. b(y-x) ? a(y-x)
//5. since y-x >= 0 and b >= a,
//6. hence the left side is larger.
//7. so pair the 2 arrays increasingly

//[B complexity
//1. similar to "merge k sorted list" --> O(mn * logm)
//2. sort the big array --> O(mn * logmn) = O(mn * logn)

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
    long long maxSpending(vector<vector<int>>& values) {
        vector<long long> val;
        for(const vector<int>& value: values)
            for(const int& v: value)
                val.push_back(v);
        
        sort(val.begin(), val.end());

        long long ans = 0;
        for(long long d=1;d<=(long long)val.size();d++)
            ans += d * val[d - 1];
        return ans;
    }
};
