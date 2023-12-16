//m0
//1. use ordered tree map.

//2. different remove algorithm for the case when the old interval covers the removing interval.

#include<map>
#include<iterator> //prev() next()
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class RangeModule {
public:
    //left --> right
    map<int, int> treemap;

    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto in_left = treemap.lower_bound(left);
        auto erase_begin = in_left;

        if(treemap.size() && in_left != treemap.begin() && left <= prev(in_left)->second ){
            //add: [left, right), so <=

            //partial overlaps, so extend leftwards
            left = prev(in_left)->first;

            erase_begin = prev(in_left);
        }


        //we can choose to merge [left, right) [right, right2) or not.
        //here we merge, so query can be done in 2 lines.
        auto out_right = treemap.upper_bound(right);

        if(treemap.size() && out_right != treemap.begin() && right < prev(out_right)->second ){
            //partial overlaps, so extend rightwards
            right = prev(out_right)->second;
        }


        //NOTE: includes the case when 1 old interval covers the new interval
        treemap.erase(erase_begin, out_right);

        treemap[left] = right;
    }
    
    bool queryRange(int left, int right) {

        auto in_left = treemap.upper_bound(left);
        if(treemap.size() == 0 || in_left == treemap.begin()){
            return false;
        }

        return right <= prev(in_left)->second;
    }
    
    void removeRange(int left, int right) {

        auto out_right = treemap.lower_bound(right);
        //remove: [left, right), so lower_bound as the erase end.
        if(treemap.size() && out_right != treemap.begin() && right < prev(out_right)->second ){
            //partial overlaps, so make a new interval, and the old interval will be erased

            //NOTE: ok for the case when the old interval covers the new interval
            treemap[right] = prev(out_right)->second;
            //may be the same old interval if it starts at right
        }


        auto in_left = treemap.lower_bound(left);

        if(treemap.size() && in_left != treemap.begin() && left < prev(in_left)->second ){
            //remove: [left, right), so <

            //partial overlaps, so cut the left out

            //NOTE: ok for the case when the old interval covers the new interval
            prev(in_left)->second = left;
            //NOTE: must do right first, so the above line will be good.
        }



        //NOTE: must update iterator, after updating the map
        out_right = treemap.lower_bound(right);
        in_left = treemap.lower_bound(left);

        //doesn't include the old interval [right, ??), since we used lower_bound
        //if we use upper_bound, then it will be missing.
        treemap.erase(in_left, out_right);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
