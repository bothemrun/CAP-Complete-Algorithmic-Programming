#define MAX_KEY ((int)1e6)
#define NO (INT_MAX)
#include<limits.h>
class MyHashMap {
public:
    vector<int> umap;
    MyHashMap() {
        umap = vector<int>(MAX_KEY+1, NO);
    }
    
    void put(int key, int value) {
        umap[key] = value;
    }
    
    int get(int key) {
        if(umap[key] == NO)return (-1);
        else return umap[key];
    }
    
    void remove(int key) {
        umap[key] = NO;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
