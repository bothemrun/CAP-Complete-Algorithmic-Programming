#include<list>
#include<unordered_map>
#include<utility>
class LRUCache {
private:
    int capacity;
    list<pair<int,int>> dll;
    unordered_map<int, list<pair<int,int>>::iterator > key2dll_iter;
    inline void move_front(list<pair<int,int>>::iterator it){
        dll.splice(dll.begin(), dll, it);//NOTE: stl function faster
        return;
        
        /*dll.push_front( {it->first, it->second} ); //(*it);//copy or move
        int key = it->first;
        dll.erase(it);
        key2dll_iter[key] = dll.begin();*/
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto f = key2dll_iter.find(key);
        if(f == key2dll_iter.end())return (-1);
        
        //move to front
        int val = f->second->second;//list iter destroyed
        move_front(f->second);
        return val;
    }
    
    void put(int key, int value) {
        auto f = key2dll_iter.find(key);
        if(f != key2dll_iter.end()){
            f->second->second = value;
            move_front(f->second);
            return;
        }
        
        if(dll.size() == capacity){
            int back_key = dll.back().first;
            dll.pop_back();
            key2dll_iter.erase(back_key);
        }
        dll.push_front( {key,value} );
        key2dll_iter[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
