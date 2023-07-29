//m0
//sweep line, with tree map
//O(n^2) due to small n.
//traversing the tree map takes O(n) amortized, not O(nlogn)
//since we visit each tree node for at most 3 times.

#include<map>
#include<algorithm>

class MyCalendarThree {
public:
    map<int, int> sweep_treemap;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        sweep_treemap[startTime]++;
        sweep_treemap[endTime]--;

        //O(n)
        //traversing the tree map takes O(n) amortized, not O(nlogn)
        //since we visit each tree node for at most 3 times.
        int max_booking = 0;

        int cur_sweep = 0;
        for(const auto& [key, val]: sweep_treemap){
            cur_sweep += val;

            max_booking = max(max_booking, cur_sweep);
        }

        return max_booking;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
