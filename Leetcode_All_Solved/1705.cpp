//greedy: eat the earliest deadline apple.
//proof: 
//1. assume the earliest deadline is today.
//(case 1) eat later deadline apple: total apples = 1 + 0(rotten today)
//(case 2) eat the earliest dealine: total apples = 1 + (1 possibly eaten later)

//chioces:
//1. discard rotten apples
//2. eat 1 apple: pop from heap top
//3. add new apples

//complexity:
//1. after apples are all grown,
//there are still at most O(2e4) boxes of apples,
//and rotten in at most O(2e4) days
//so computing 1 apple each time costs O(2e4 + 2e4) + O(heap cost), ok.

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
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();

        //(due date, apples)
        auto cmp = [](const PII& a, const PII& b){
            return a.first > b.first;//min heap for due date
            //doesn't maater for boxes of apples with the same due date
        };
        priority_queue<PII, vector<PII>, decltype(cmp) > minheap(cmp);


        int cnt = 0;

        auto eat1_discard = [&minheap, &cnt](const int& day){
            //discard rotten
            while(minheap.size() && minheap.top().first <= day){
                minheap.pop();
            }

            if(minheap.size() == 0) return;

            //eat 1 apple today
            cnt++;

            auto [due, apple] = minheap.top();
            minheap.pop();
            if(--apple > 0) minheap.push(PII(due, apple));
        };

        int i;
        for(i=0;i<n;i++){
            minheap.push(PII(i+days[i], apples[i]));

            eat1_discard(i);
        }

        while(minheap.size()){
            eat1_discard(i++);
        }

        return cnt;
    }
};
