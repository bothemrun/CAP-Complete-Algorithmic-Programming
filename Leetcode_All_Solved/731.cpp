//m0
//sweep line with tree map.

//insert first then check. if triple booking, then roll back.
//this way, we can avoid different cases of comparing start & end times.

//O(n^2) to due small n.

//traversing the tree map takes O(n) amortized, not O(nlogn)
//since we visit each tree node for at most 3 times.

#include<map>

class MyCalendarTwo {
public:
    map<int,int> sweep_treemap;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        sweep_treemap[start]++;
        sweep_treemap[end]--;

        int cur_sweep = 0;
        for(const auto& [time, diff]: sweep_treemap){
            cur_sweep += diff;

            if(cur_sweep == 3){
                //roll back
                sweep_treemap[start]--;
                sweep_treemap[end]++;
                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
