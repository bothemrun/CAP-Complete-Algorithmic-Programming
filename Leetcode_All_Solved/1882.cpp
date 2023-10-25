//dual priority queue + 1 queue, O(nlogm)
#define PII pair<int,int>
#include<queue>
#include<utility>
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
        //(task idx)
        queue<int> task_q;

        //(free server idx)
        auto cmp_free = [&servers](const int& a, const int& b){
            if(servers[a] != servers[b])
                return servers[a] > servers[b];//weight minheap
            else return a > b;//server idx minheap
        };
        priority_queue<int, vector<int>, decltype(cmp_free)> free_heap(cmp_free);

        //(used server idx, available time)
        //NOTE: lambda calls another lambda by reference.
        auto cmp_busy = [&cmp_free](const PII& a, const PII& b){
            if(a.second != b.second)
                return a.second > b.second;//minheap for avaible time
            else return cmp_free(a.first, b.first);
        };
        priority_queue<PII, vector<PII>, decltype(cmp_busy)> busy_heap(cmp_busy);


        int n = servers.size(), m = tasks.size();
        for(int i=0;i<n;i++)
            free_heap.push(i);


        vector<int> ans(m);

        for(int j=0;j<m;j++){
            task_q.push(j);

            //busy to free
            int time = j;
            while(busy_heap.size() && busy_heap.top().second <= time){
                auto [server_i, avail_time] = busy_heap.top();
                busy_heap.pop();

                free_heap.push(server_i);
            }

            //task queue get free to busy
            while(free_heap.size() && task_q.size()){
                int task_i = task_q.front();
                task_q.pop();

                int free_i = free_heap.top();
                free_heap.pop();

                ans[task_i] = free_i;

                busy_heap.push(PII(free_i, j+tasks[task_i]));
            }
        }


        long long time = m;
        while(task_q.size()){
            assert(free_heap.size() == 0);
            assert(busy_heap.size());

            auto [server_i, avail_time] = busy_heap.top();
            busy_heap.pop();

            time = avail_time;

            int task_i = task_q.front();
            task_q.pop();

            ans[task_i] = server_i;

            busy_heap.push(PII(server_i, time + tasks[task_i]));
        }

        return ans;
    }
};
