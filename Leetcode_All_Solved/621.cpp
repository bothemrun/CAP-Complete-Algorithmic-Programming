//m0
//greedy construction + heap O(task.size() * log(26))

//Problem: same task between adjacent windows
//1. let window = 3, the 1st window has "abc"
//2. how can we ensure that the 2nd window has "bac" ??!!

//3. for the same count, additionally, we impose the alphabetic order.
//4. since the tasks in 1st window all decrement by 1,
//5. hence, if we want to use the same tasks in 2nd window, 
//6. we can still maintain task "b"'s distance.

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
    int leastInterval(vector<char>& tasks, int n) {
        int task2cnt[256] = {0};
        for(const char& task: tasks)
            task2cnt[task]++;
        
        auto cmp = [](const int& a, const int& b){
            return a<b;//max heap
        };
        priority_queue<int, vector<int>, decltype(cmp) > maxheap(cmp);

        for(char task='A';task<='Z';task++)if(task2cnt[task] != 0)
            maxheap.push(task2cnt[task]);
        

        int window = n+1;
        int time = 0;
        while(maxheap.size()){
            vector<int> repush;
            int old_heap_size = maxheap.size();

            for(int i=0;i<window;i++){
                if(maxheap.size() == 0) break;
                int cnt = maxheap.top();
                maxheap.pop();
                if(--cnt > 0) repush.push_back(cnt);
            }

            for(const int& cnt: repush)
                maxheap.push(cnt);
            

            if(maxheap.size() == 0)
                time += old_heap_size;
            else time += window;
        }

        return time;
    }
};
