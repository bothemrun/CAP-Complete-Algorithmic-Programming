//greedy construction + heap O(s.size() * log26)
//more difficult than 621 Task Scheduler

//Problem: same task between adjacent windows
//1. let window = 3, the 1st window has "abc"
//2. how can we ensure that the 2nd window has "bac" ??!!

//3. for the same count, additionally, we impose the alphabetic order.
//4. since the tasks in 1st window all decrement by 1,
//5. hence, if we want to use the same tasks in 2nd window, 
//6. we can still maintain task "b"'s distance.

#define PIC pair<int, char>
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
    string rearrangeString(string s, int k) {
        int task2cnt[256] = {0};

        //edge case: TLE without it
        if(k==0) return s;

        for(const char& task: s) task2cnt[task]++;

        auto cmp = [](const PIC& a, const PIC& b){
            if(a.first != b.first) return a.first < b.first;//max heap
            return a.second > b.second;//just maintain any order between same counts
        };
        priority_queue<PIC, vector<PIC>, decltype(cmp) > maxheap(cmp);

        for(char task='a';task<='z';task++)if(task2cnt[task] != 0)
            maxheap.push(PIC(task2cnt[task], task));
        

        string ans = "";
        int window = k;
        while(maxheap.size()){
            vector<PIC> repush;

            for(int i=0;i<window;i++){
                if(maxheap.size() == 0){
                    if(repush.size() != 0) return "";
                    else break;
                }

                auto [cnt, task] = maxheap.top();
                maxheap.pop();

                ans += task;

                if(--cnt > 0) repush.push_back( PIC(cnt, task) );
            }

            for(const PIC& x: repush)
                maxheap.push(x);
        }

        return ans;
    }
};
