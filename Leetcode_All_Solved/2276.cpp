//m0
//sweep line by treemap.
//by prev(iterator). it = map.erase(it).

#include<map>
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class CountIntervals {
public:
    int cover = 0;
    //start --> end
    map<int,int> sweep_treemap;

    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        auto it = sweep_treemap.lower_bound(left);
        if(it != sweep_treemap.begin() && left <= prev(it)->second )
            it = prev(it);
        
        //newly enlarged bounds
        int new_left = left;
        int new_right = right;

        //iterate thru all overlapping intervals, including partial overlaps
        for(;it != sweep_treemap.end() && it->first <= right; it = sweep_treemap.erase(it) ){
            //NOTE: dealing with partial overlapping
            int start = max(left, it->first);
            int end = min(right, it->second);

            cover -= end - (start-1);

            //newly enlarged bounds
            new_left = min(new_left, it->first);
            new_right = max(new_right, it->second);
        }

        cover += right - (left-1);

        //newly enlarged bounds
        sweep_treemap[new_left] = new_right;
        //sweep_treemap[left] = right;
    }
    
    int count() {
        return cover;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
