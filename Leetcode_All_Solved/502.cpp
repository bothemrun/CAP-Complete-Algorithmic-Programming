//Thinking Process:

//[A] dp choose or not?
//1. the order of choice is not sequential.

//[B] some way to consider the non-sequential order?
//1. heap.

#include<algorithm>
#include<queue>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<int> idx(n);
        for(int i=0;i<n;i++) idx[i] = i;
        auto cmp1 = [&capital](const int& i, const int& j){
            return capital[i] < capital[j];
        };
        sort(idx.begin(), idx.end(), cmp1);

        auto cmp2 = [](const int& a, const int& b){
            return a < b;//max heap for profits
        };
        priority_queue<int, vector<int>, decltype(cmp2) > maxheap(cmp2);


        int wealth = w;//no overflow
        int i = 0;
        while(i<n && k != 0){
            //all projects with capital <= wealth
            bool go_while = false;
            while(i<n && wealth >= capital[ idx[i] ]){
                maxheap.push(profits[ idx[i++] ]);
                go_while = true;
            }
            if(go_while == false) break;


            //accumulate enought wealth for the next capital
            if(!(i<n)) break;
            const int& next_capital = capital[ idx[i] ];
            while(maxheap.size() && k != 0 && wealth < next_capital){
                k--;
                wealth += maxheap.top();
                maxheap.pop();
            }
        }

        //NOTE: deplete k
        while(maxheap.size() && k != 0){
            k--;
            wealth += maxheap.top();
            maxheap.pop();
        }

        return wealth;
    }
};
