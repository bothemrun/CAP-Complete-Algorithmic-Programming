//1882. Process Tasks Using Servers
//m0
////dual priority queue without a task queue
//without while loop to deplete remaining tasks in 1882 method 0.

#define PIL pair<int, long long>

#include<utility>
#include<queue>
#include<algorithm>
#include<iterator>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        //(free idx)
        auto cmp_free = [](const int& a, const int& b){
            return a > b;//minheap for room number
        };
        priority_queue<int, vector<int>, decltype(cmp_free) > free_heap(cmp_free);

        //(busy idx, available time)
        //NOTE: lambda calls another lambda by reference
        auto cmp_busy = [&cmp_free](const PIL& a, const PIL& b){
            if(a.second != b.second)
                return a.second > b.second;//minheap for available time
            else return cmp_free(a.first, b.first);
        };
        priority_queue<PIL, vector<PIL>, decltype(cmp_busy) > busy_heap(cmp_busy);


        sort(meetings.begin(), meetings.end());

        vector<int> used_cnt(n, 0);
        for(int i=0;i<n;i++)
            free_heap.push(i);
        


        for(int i=0;i<(int)meetings.size();i++){
            int start = meetings[i][0];
            int end = meetings[i][1];

            //busy to free
            long long time = start;
            while(busy_heap.size() && busy_heap.top().second <= time){
                auto [busy_i, avail_time] = busy_heap.top();
                busy_heap.pop();

                free_heap.push(busy_i);
            }

            //assign this meeting task to either:
            //1. a free room, if 1 exists.
            //2. otherwise, definitely the top of the busy rooms,
            //'cuz (a) the task queue is FIFO
            //'cuz (b) the cmp_free is isomorphic to cmp_busy now.
            if(free_heap.size()){
                int free_i = free_heap.top();
                free_heap.pop();

                busy_heap.push(PIL(free_i, end ));

                used_cnt[free_i]++;
            }else{
                //isomorphic to pop 1 from busy heap into free heap,
                //then pop 1 from task queue & free heap
                auto [busy_i, avail_time] = busy_heap.top();
                busy_heap.pop();

                int duration = (end-1) - (start-1);
                busy_heap.push(PIL(busy_i, avail_time + duration ));

                used_cnt[busy_i]++;
            }
        }

        //max_element returns the smallest index if values are the same.
        return distance(
            used_cnt.begin(),
            max_element(used_cnt.begin(), used_cnt.end())
        );
    }
};
