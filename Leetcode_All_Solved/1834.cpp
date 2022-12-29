#include<algorithm>
#include<queue>
#include<utility>
#include<assert.h>
bool cmp_fn(const vector<int>& a, const vector<int>& b){
    return a[0] < b[0];//ascending only in enqueueTime
}

class cmp_class{
public:
    bool operator()(const pair<int,int>& a, const pair<int,int>& b){
        if(a.first != b.first)return a.first > b.first; //min heap for processingTime
        else return a.second > b.second; //min heap for task index
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>> tasksort(n, vector<int>(3));
        for(int i=0;i<n;i++)
            tasksort[i] = {tasks[i][0], tasks[i][1], i };

        sort(tasksort.begin(), tasksort.end(), cmp_fn);



        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp_class > min_heap;

        vector<int> order;

        //NOTE: cur_time init: is not just for convenience, it ensures the starting
        //NOTE: overflow
        long long cur_time = tasksort[0][0];//n >= 1, first tasksort's enqueueTime
        
        int task_i = 0;

        while(true){

            //add all subsequent tasks with enqueueTime <= cur_time

            while(task_i < n && tasksort[task_i][0] <= cur_time ){

                min_heap.push( pair<int,int>( tasksort[task_i][1], tasksort[task_i][2] ) );

                task_i++;
            }
            

            //execute 1 task from heap

            assert(min_heap.size() != 0);
            order.push_back( min_heap.top().second );
            int processingTime = min_heap.top().first;
            min_heap.pop();

            //stopping condition
            if(order.size() == n)break;


            //update cur_time with this task's processingTime
            //NOTE: cur_time += processingTime;
            //NOTE: in case last end time <<< next enqueueTime
            if(min_heap.size() == 0){
                assert(task_i < n);
                //NOTE: cur_time = tasksort[task_i][0];
                cur_time = max(cur_time + processingTime, (long long)tasksort[task_i][0] );
            }else cur_time += processingTime;

            //if(task_i < n)
                //cur_time = max(cur_time + processingTime, (long long)tasksort[task_i][0] );
        }

        return order;
    }
};




