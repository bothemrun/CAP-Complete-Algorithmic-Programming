//m1
//all strictly in O(1)
class RandomizedSet {
public:
    vector<int> vec;
    unordered_map<int, int> val2idx;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(val2idx.find(val) != val2idx.end()) return false;
        
        val2idx[val] = vec.size();
        vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        //crucial operation
        if(val2idx.find(val) == val2idx.end()) return false;
        
        //ok if only 1 element
        int idx = val2idx[val];
        val2idx[vec.back()] = idx;
        vec[idx] = vec.back();
        
        val2idx.erase(val);
        vec.pop_back();
        return true;
    }
    
    int getRandom() {
        return vec[ rand()%(int)vec.size() ];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
