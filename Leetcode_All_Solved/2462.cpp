#include<queue>
#include<utility>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class cmp_class{
public:
    bool operator()(const pair<int,int>& a, const pair<int,int>& b){
        if(a.first != b.first) return a.first > b.first;//min heap in cost, sink down
        else return a.second > b.second;//min heap in index, sink down
    }
};

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp_class > minheap;

        int left = (0-1) + candidates + 1;
        int right = (n-1 + 1) - candidates - 1;
        if(left > right){
            for(int i=0;i<n;i++)
                minheap.push( pair<int,int>(costs[i], i) );
        }else{
            for(int i=0;i<left;i++)
                minheap.push( pair<int,int>(costs[i], i) );
            for(int i=n-1;i>right;i--)
                minheap.push( pair<int,int>(costs[i], i) );
        }

        
        long long cost_sum = 0;
        for(int hire=0;hire<k;hire++){
            //NOTE: trap: const auto& [cost, idx] = minheap.top();
            //NOTE: can't use reference, since we have pop() !!!
            auto [cost, idx] = minheap.top();
            
            cost_sum += cost;
            minheap.pop();


            //update
            if(left > right) continue;

            if(idx < left)
                minheap.push( pair<int,int>(costs[left], left++) );
            else minheap.push( pair<int,int>(costs[right], right--) );
        }

        return cost_sum;
    }
};
