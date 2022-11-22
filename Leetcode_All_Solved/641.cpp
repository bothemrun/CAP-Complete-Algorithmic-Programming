#include<list>
class MyCircularDeque {
public:
    list<int> dll;
    int max_size;
    int cur_size;
    MyCircularDeque(int k) {
        max_size = k;
        cur_size = 0;
    }
    
    bool insertFront(int value) {
        if(cur_size+1 > max_size)return false;
        dll.push_front(value);
        cur_size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(cur_size+1 > max_size)return false;
        dll.push_back(value);
        cur_size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())return false;
        dll.pop_front();
        cur_size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())return false;
        dll.pop_back();
        cur_size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty())return (-1);
        return dll.front();
    }
    
    int getRear() {
        if(isEmpty())return (-1);
        return dll.back();
    }
    
    bool isEmpty() {
        return cur_size == 0;
    }
    
    bool isFull() {
        return cur_size == max_size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
