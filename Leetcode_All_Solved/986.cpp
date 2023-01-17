#include<assert.h>
#include<queue>
#include<utility>
class cmp_class{
public:
    bool operator()(const pair<int,int>& a, const pair<int,int>& b){
        if(a.first != b.first)return a.first > b.first;//min heap in coordinates
        else return a.second < b.second;
        //NOTE: max heap, start(+1) is superior than end(-1)
    }
};
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp_class> min_heap;

        for(const vector<vector<int>>& list: {firstList, secondList} ){
            for(const vector<int>& i: list){
                min_heap.push( pair<int,int>(i[0], 1) );
                min_heap.push( pair<int,int>(i[1], (-1)) );
            }
        }

        vector<vector<int>> inter;
        int sweep = 0;
        int sweep2_start;
        while(min_heap.size() != 0){
            pair<int,int> p = min_heap.top();
            min_heap.pop();

            if(sweep == 2){
                assert(p.second == (-1));
                inter.push_back( vector<int>({sweep2_start, p.first}) );
            }
            sweep += p.second;
            if(sweep == 2){
                sweep2_start = p.first;
            }
        }

        return inter;
    }
};


