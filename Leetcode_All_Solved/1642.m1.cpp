//m1
//O(nlogn) greedy + heap

#include<queue>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();

        auto cmp = [](const int& a, const int& b){
            return a<b;//max heap
        };
        priority_queue<int, vector<int>, decltype(cmp)> maxheap(cmp);

        int building;
        for(building=0;building<n-1;building++){
            int diff = heights[building+1] - heights[building];
            if(diff <= 0) continue;

            //NOTE: greedy: first use bricks
            bricks -= diff;
            //NOTE: then use a ladder if necessary emergency
            maxheap.push(diff);
            if(bricks < 0){
                if(ladders-- == 0) break;
                if(maxheap.size() == 0) break;

                bricks += maxheap.top();
                maxheap.pop();
            }
        }

        return building;
    }
};
