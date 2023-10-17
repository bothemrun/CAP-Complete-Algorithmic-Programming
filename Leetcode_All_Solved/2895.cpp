//greedy + O(nlogn) due to sorting

//Greedy: sort processor time and tasks,
//then match them in the reverse order.

//Greedy Proof:

//[A] How to Match?

//(0) denote a match of processor start time and task by (a, b)

//(1) for a max finish time (a, b), 
//and a match (x, y) with a>x & b>y --> (the same order)

//(2) then swap them will make the max finish time better --> (reverse order)

//(3) repeat (1)


//[B] Why Follow The Order Strictly?

//(1) assume all are arranged by the reverse order, with max finish time (a, b)

//(2) without loss of generality, 
//assume (x, y) with a<x & b>y
//in the strict reverse order 
//has a shorter max fisnish time

//(3) swapping them makes (a,y) & (x,b)
//better with a picture.
//then the finish times: a+y b+x

//(4) b+x definitely > the original a+b or x+y
//(5) contradict.  proof by contradiction.

#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int n = processorTime.size();
        
        sort(tasks.begin(), tasks.end());
        sort(processorTime.begin(), processorTime.end());

        int max_finish = processorTime.front() + tasks.back();
        //NOTE: optim: not O(4n), just O(n)
        for(int i=0;i<n;i++)
            max_finish = max(
                max_finish,
                processorTime[n-1-i] + tasks[ 4*i + 3 ]
            );

        return max_finish;
    }
};
