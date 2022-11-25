#include<deque>
#include<assert.h>
class FrontMiddleBackQueue {
public:
    deque<int> deque1;
    deque<int> deque2;
    //middle is at the back of deque1 (both ways ok)
    FrontMiddleBackQueue() {
    }
    ~FrontMiddleBackQueue(){
        deque1.clear();
        deque2.clear();
    }
    inline int s1(){return deque1.size();}
    inline int s2(){return deque2.size();}
    inline void deque1to2(){
        assert(s1() != 0);
        deque2.push_front( deque1.back() );
        deque1.pop_back();
    }
    inline void deque2to1(){
        assert(s2() != 0);
        deque1.push_back( deque2.front() );
        deque2.pop_front();
    }
    inline void maintain_middle(){
        // (k+1 & k) or (k & k)
        if(s1() == s2() || s1() == s2()+1)return;
        
        if(s1() > s2()){// s1-s2 >= 2
            while( !(s1() - s2() <= 1) ) deque1to2();
        }else{// s2-s1 >= 1 --> below won't stop at (k,k+1)
            while( !(s1() - s2() >= 0) ) deque2to1();
        }
    }
    void pushFront(int val) {
        deque1.push_front(val);
        maintain_middle();
    }
    void pushMiddle(int val) {
        if( (s1() + s2())%2 == 0 ){
            deque1.push_back(val);
        }else{
            deque1to2();
            deque1.push_back(val);
        }
    }
    void pushBack(int val) {
        deque2.push_back(val);
        maintain_middle();
    }
    int popFront() {
        if(s1()+s2() == 0)return (-1);
        
        assert(s1() != 0);//(k+1, k) or (k,k)
        int val = deque1.front();
        deque1.pop_front();
        maintain_middle();
        return val;
    }
    int popMiddle() {
        if(s1()+s2() == 0)return (-1);
        
        assert(s1() != 0);//(k+1,k) or (k,k)
        int val = deque1.back();
        deque1.pop_back();
        maintain_middle();
        return val;
    }
    int popBack() {
        if(s1()+s2() == 0)return (-1);
        
        if(s2() == 0) deque1to2();//'cuz (k+1,k) or (k,k)
        assert(s2() != 0);
        int val = deque2.back();
        deque2.pop_back();
        maintain_middle();
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
