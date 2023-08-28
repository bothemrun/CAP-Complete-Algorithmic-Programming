#include<queue>
class MyStack {
public:
    /** Initialize your data structure here. */
    //v3: 1 queue, push O(1), pop O(n)
    //v1: 2 queues, push O(1), pop O(n)
    vector<queue<int>> q;
    int q_id; // idx of the push queue
    
    MyStack() {
        //v1
        q.resize(2, queue<int>());
        q_id = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        //v1
        q.at(q_id).push(x);
    }
    
    void transfer_queue(){
        // v1
        while(q.at(q_id).size() > 1 ){
            q.at( (q_id+1)%2 ).push( q.at(q_id).front() );
            q.at(q_id).pop();
        }
    }
    void transfer_id(){
        q_id = (q_id + 1)%2;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        //v1
        transfer_queue();
        int top = q.at(q_id).front();
        q.at(q_id).pop();
        transfer_id();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        //v1
        transfer_queue();
        int top = pop();
        push(top);
        return top;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        //v1
        return q.at(q_id).size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
