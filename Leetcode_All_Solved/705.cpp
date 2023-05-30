#define max_key ((int)1e6 + 1)
class MyHashSet {
public:
    bool uset[max_key] = {0};
    MyHashSet() {
        
    }
    
    void add(int key) {
        uset[key] = true;
    }
    
    void remove(int key) {
        uset[key] = false;
    }
    
    bool contains(int key) {
        return uset[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
