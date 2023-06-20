#define heap_size 5
#define max_id 1001
#include<queue>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class cmp_class{
public:
    bool operator()(const int& a, const int& b){
        return a > b;//min heap
    }    
};

class Solution {
public:
    vector< priority_queue<int, vector<int>, cmp_class> > minheap;

    inline void push(const int& val, const int& id){
        minheap[id].push(val);
        if(minheap[id].size() > heap_size) minheap[id].pop();
    }

    vector<vector<int>> highFive(vector<vector<int>>& items) {
        minheap.resize(max_id);

        for(const vector<int>& item: items)
            push(item[1], item[0]);
        
        vector<vector<int>> ans;
        for(int id=1;id<max_id;id++)if(minheap[id].size() != 0){
            int sum = 0;
            while(minheap[id].size() != 0){
                sum += minheap[id].top();
                minheap[id].pop();
            }

            ans.push_back( vector<int>({id, sum / heap_size}) );
        }

        return ans;
    }
};
