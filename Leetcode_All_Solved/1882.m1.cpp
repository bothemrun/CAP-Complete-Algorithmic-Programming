//m1
//dual priority queue without a task queue
//without while loop to deplete remaining tasks in method 0.
#define PIL pair<int, long long>
#include<utility>
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
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        //(free server idx)
        auto cmp_free = [&servers](const int& a, const int& b){
            //both minheap
            if(servers[a] != servers[b])
                return servers[a] > servers[b];
            else return a > b;
        };
        priority_queue<int, vector<int>, decltype(cmp_free) > free_heap(cmp_free);

        //(busy server idx, available time)
        //NOTE: lambda uses another lambda by reference
        auto cmp_busy = [&cmp_free](const PIL& a, const PIL& b){
            if(a.second != b.second)
                return a.second > b.second;//min heap
            else return cmp_free(a.first, b.first);
        };
        priority_queue<PIL, vector<PIL>, decltype(cmp_busy) > busy_heap(cmp_busy);



        int n = servers.size(), m = tasks.size();
        vector<int> ans(m);

        for(int i=0;i<n;i++)
            free_heap.push(i);
        

        for(int j=0;j<m;j++){
            //busy to free
            int time = j;
            while(busy_heap.size() && busy_heap.top().second <= time){
                auto [busy_i, avail_time] = busy_heap.top();
                busy_heap.pop();

                free_heap.push(busy_i);
            }

            //assign this task to either:
            //1. a free server if 1 exists.
            //2. otherwise, definitely the top of the busy server,
            //'cuz (a) the task queue is FIFO
            //'cuz (b) the free_cmp & busy_cmp are isomorphic now.
            if(free_heap.size()){
                //use a free server
                int free_i = free_heap.top();
                free_heap.pop();

                busy_heap.push(PIL(free_i, j+ tasks[j] ));

                ans[j] = free_i;
            }else{
                //isomorphic to pop 1 from busy into free heap,
                //then pop 1 from free heap & the task queue
                auto [busy_i, avail_time] = busy_heap.top();
                busy_heap.pop();

                busy_heap.push(PIL(busy_i, avail_time + tasks[j] ));

                ans[j] = busy_i;
            }
        }

        return ans;
    }
};
