//m1
//memory leak, destructor
class Node{
public:
    int val;
    class Node* next;
    class Node* prev;
    Node(int val_){val=val_; next=nullptr; prev=nullptr;}
};
class MyCircularDeque {
public:
    int cur_size = 0;
    int max_size;
    class Node *head = nullptr, *tail = nullptr;
    MyCircularDeque(int k) {
        max_size = k;
    }
    ~MyCircularDeque(){
        while(head != nullptr){
            class Node* next = head->next;
            delete head;
            head = next;
        }
    }
    
    bool insertFront(int value) {
        if(isFull())return false;
        
        class Node* new_node = new Node(value);
        if(isEmpty()){
            tail = new_node;
            head = new_node;
        }else{
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
        }
        
        cur_size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())return false;
        
        class Node* new_node = new Node(value);
        if(isEmpty()){
            head = new_node;
            tail = new_node;
        }else{
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        
        cur_size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())return false;
        
        if(head == tail){
            delete head;
            head = nullptr;
            tail = nullptr;
        }else{//NOTE: old size >= 2
            class Node* old_next = head->next;
            old_next->prev = nullptr;
            delete head;
            head = old_next;
            //NOTE: no updating tail
        }
        
        cur_size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())return false;
        
        if(head == tail){
            delete tail;
            tail = nullptr;
            head = nullptr;
        }else{
            //NOTE: old size >= 2
            class Node* old_prev = tail->prev;
            old_prev->next = nullptr;
            delete tail;
            tail = old_prev;
            //NOTE: no updating head
        }
        
        cur_size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty())return (-1);
        return head->val;
    }
    
    int getRear() {
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
