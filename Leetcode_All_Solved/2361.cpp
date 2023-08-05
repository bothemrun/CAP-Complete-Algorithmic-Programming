//m0
//recursion with memo

#define notyet (-1)
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

enum{
    Regular,
    Express
};

class Solution {
public:
    vector<int>* regular_p;
    vector<int>* express_p;
    int expressCost;

    vector<vector<long long>> memo;
    long long enum2(const int& i, const int& route){
        if(i<0){
            return (route==Express)? expressCost:0;
        }

        if(memo[i][route] != notyet) return memo[i][route];

        long long r = enum2(i-1, Regular);
        long long e = enum2(i-1, Express);
        memo[i][Regular] = min(
            r + regular_p->at(i),
            e + express_p->at(i)
        );
        memo[i][Express] = min(
            r + regular_p->at(i) + expressCost,
            e + express_p->at(i)
        );

        return memo[i][route];
    }

    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        this->expressCost = expressCost;
        regular_p = &regular;
        express_p = &express;

        int n = regular.size();
        vector<long long> ans(n);

        memo.resize(n, vector<long long>(2, notyet));
        for(int i=0;i<n;i++)
            ans[i] = min(
                enum2(i, Regular),
                enum2(i, Express)
            );
        return ans;
    }
};
