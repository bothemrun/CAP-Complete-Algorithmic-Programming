class Node{
public:
    int val;
    class Node* next;
    Node(int val_){val = val_; next = nullptr;}
};
class MyCircularQueue {
public:
    int cur_size;
    int max_size;
    class Node *head, *tail;
    MyCircularQueue(int k) {
        cur_size = 0;
        max_size = k;
        head = nullptr;
        tail = nullptr;
    }
    
    bool enQueue(int value) {
        if(isFull())return false;
        
        class Node* new_node = new Node(value);
        if(isEmpty()){
            tail = new_node;
            head = new_node;
        }else{
            tail->next = new_node;
            tail = tail->next;
        }
        
        cur_size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        
        class Node* old_head = head;
        head = head->next;
        if(head == nullptr)tail = nullptr;
        
        delete old_head;//NOTE: memory leak
        
        cur_size--;
        return true;
    }
    
    int Front() {
        if(isEmpty())return (-1);
        return head->val;
    }
    
    int Rear() {
        if(isEmpty())return (-1);
        return tail->val;
    }
    
    bool isEmpty() {
        return cur_size == 0;
    }
    
    bool isFull() {
        return cur_size == max_size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
