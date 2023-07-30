//m1
//sweep line with tree map, O(nlogn) with binary search of tree map.
//treemap of start or end time, instead of pair(start, end)

#include<map>
#include<assert.h>

class MyCalendar {
public:
    map<int,int> sweep_treemap;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        //auto it = sweep_treemap.lower_bound(start);
        auto it = sweep_treemap.upper_bound(start);

        if(it != sweep_treemap.end()){
            int time = it->first;
            int diff = it->second;
            if(diff > 0){//start
                if(time < end) return false;
            }else if(diff < 0){//end
                if(start < time) return false;
            }else{//2 intervals merged
                //NOTE: we can also deal with diff==0, where 2 intervals merged.
                assert(false);
            }
        }

        sweep_treemap[start]++;
        sweep_treemap[end]--;

        //deal with 2 intervals merged
        if(sweep_treemap[start] == 0) sweep_treemap.erase(start);
        if(sweep_treemap[end] == 0) sweep_treemap.erase(end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
