//m0
//sliding window

//[Thinking Process]


//[A] range endpoints on nums?

//1. first reverse thinking.
//2. assume now we have found the satisfied range.
//3. it covers at least 1 number from each list.
//4. for the min & max among the numbers covered,
//5. we can shrink the range endpoints to these min & max to get a smaller range.



//[B] group index
//1. we wanna find the smallest window/range with all group index i covered.
//2. sounds like a sliding window.

//[C] merge
//1. merge all of them with pair(nums[i][j], i),
//2. by a standard merge k sorted list algorithm.

//[D]
//O(nlogk).
//n := count of all numbers from all lists.

#include<queue>
#include<assert.h>
#include<limits.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class T{
public:
    int num;
    int group;
    T(int n, int g){
        num = n;
        group = g;
    }
};

class Solution {
public:
    vector<class T*> ng;
    int m;

    inline void merge_k_sorted_list(const vector<vector<int>>& nums){

        vector<int> idx(m, 0);

        auto cmp = [](const T* a, const T* b){
            return a->num > b->num;//min heap for num
        };
        priority_queue<T*, vector<T*>, decltype(cmp)> minheap(cmp);

        for(int i=0;i<m;i++)
            minheap.push( new T(nums[i][0], i) );
        
        while(minheap.size() != 0){
            T* mi = minheap.top();
            minheap.pop();

            ng.push_back(mi);

            int group = mi->group;
            if(++idx[ group ] < nums[ group ].size() ){
                minheap.push( new T(nums[group][ idx[group] ], group) );
            }
        }
    }

    vector<int> smallestRange(vector<vector<int>>& nums) {
        this->m = nums.size();

        merge_k_sorted_list(nums);


        
        //sliding window
        vector<int> ans({0, INT_MAX});

        vector<int> group2cnt(m, 0);
        //[left, right] window, fix left endpoint.
        int right = (-1);
        int group_cover = 0;
        for(int left=0;left<ng.size();left++){
            while(
                right+1<ng.size() &&
                group_cover != m
            ){
                right++;
                int group = ng[right]->group;
                if(group2cnt[group]++ == 0){
                    group_cover++;
                }
            }

            if(group_cover == m){
                if( ng[right]->num - ng[left]->num < ans[1] - ans[0] ){
                    ans = { ng[left]->num, ng[right]->num };
                }
            }

            //update, drop
            int group_left = ng[left]->group;
            assert(--group2cnt[ group_left ] >= 0);
            if(group2cnt[ group_left ] == 0){
                group_cover--;
            }
        }

        return ans;
    }
};
