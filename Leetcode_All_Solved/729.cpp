//m0
//O(n^2) sweep line with treemap.

#include<map>

class MyCalendar {
public:
    map<int,int> sweep_treemap;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        sweep_treemap[start]++;
        sweep_treemap[end]--;

        //O(n)
        int cur_sweep = 0;
        for(const auto& [time, diff]: sweep_treemap){
            cur_sweep += diff;

            if(cur_sweep >= 2){
                sweep_treemap[start]--;
                sweep_treemap[end]++;
                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
