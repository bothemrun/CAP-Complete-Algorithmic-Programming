#include<utility>
#include<algorithm>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class SnapshotArray {
public:
    int cur_snap_id = 0;

    //index --> (last snap id, val), lazy update
    vector<vector<pair<int,int>>> lazy_snap;

    static bool cmp_fn(const pair<int,int>& a, const pair<int,int>& b){
        //NOTE: 
        return a.first < b.first;
    }

    SnapshotArray(int length) {
        lazy_snap.resize(
            length,
            vector<pair<int,int>>( { pair<int,int>(cur_snap_id, 0) } )
        );
    }
    
    void set(int index, int val) {
        if(lazy_snap[index].back().first == cur_snap_id)
            lazy_snap[index].back().second = val;
        else
            lazy_snap[index].push_back(pair<int,int>(cur_snap_id, val));
    }
    
    int snap() {
        return cur_snap_id++;
    }
    
    int get(int index, int snap_id) {
        //NOTE: lazy update, 
        //find: find the smallest i with its snap_id >= required snap_id
        int i = ( upper_bound(
            lazy_snap[index].begin(), 
            lazy_snap[index].end(), 
            pair<int,int>(snap_id, snap_id), //snap_id, 
            cmp_fn
        ) - lazy_snap[index].begin()
        ) - 1;

        assert(i != lazy_snap[index].size());
        assert(i>=0);

        return lazy_snap[index].at(i).second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
