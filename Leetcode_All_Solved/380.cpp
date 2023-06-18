//NOTE: all in O(1)
//NOTE: MLE if use vector map to replace hash map.
#include<unordered_map>
#include<stdlib.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class RandomizedSet {
public:
    unordered_map<int,int> val2idx;
    vector<int> vec;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(val2idx.count(val) != 0) return false;

        val2idx[val] = vec.size();
        vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(val2idx.count(val) == 0) return false;

        int vsize = vec.size();
        if( val2idx[val] != vsize-1 ){
            vec[ val2idx[val] ] = vec.back();
            val2idx[ vec.back() ] = val2idx[val];
        }

        val2idx.erase(val);
        vec.pop_back();
        return true;
    }
    
    int getRandom() {
        return vec.at( rand()%vec.size() );
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
