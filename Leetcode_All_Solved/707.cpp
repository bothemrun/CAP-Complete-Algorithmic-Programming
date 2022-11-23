class Node{
public:
    int val;
    class Node* next;
    class Node* prev;
    Node(int val_){val=val_; next=nullptr; prev=nullptr;}
};
class MyLinkedList {
public:
    int cur_size = 0;
    class Node* head = nullptr;
    MyLinkedList() {
        
    }
    ~MyLinkedList(){
        while(head != nullptr){
            class Node* next = head->next;
            delete head;
            //head = head->next;//NOTE: heap-use-after-free
            head = next;
        }
    }
    
    inline class Node* getNode(int index){
        if(index >= cur_size)return nullptr;//include 1.exceed 2.empty
        
        class Node* cur = head;
        for(int i=0;i<index;i++)
            cur = cur->next;
        return cur;
    }
    
    int get(int index) {
        class Node* cur = getNode(index);
        if(cur == nullptr)return (-1);
        else return cur->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(cur_size, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > cur_size)return;
        
        class Node* new_node = new Node(val);
        if(cur_size == 0){
            head = new_node;
        }else if(index == cur_size){
            class Node* tail = getNode(cur_size - 1);
            tail->next = new_node;
            new_node->prev = tail;
        }else{
            class Node* cur = getNode(index);
            class Node* old_pre = cur->prev;
            
            new_node->next = cur;
            cur->prev = new_node;
            
            //NOTE: case of inserting at non-head
            if(index != 0){//old_pre != nullptr
                old_pre->next = new_node;
                new_node->prev = old_pre;
            }else{
                //NOTE: case of inserting at head
                head = new_node;
            }
        }
        
        cur_size++;
    }
    
    void deleteAtIndex(int index) {
        if(cur_size == 0 || index >= cur_size)return;
        
        class Node* cur = getNode(index);
        class Node* cur_next = cur->next;
        class Node* cur_prev = cur->prev;
        //NOTE: case of tail and/or case of head (4 possibilities)
        if(cur_prev != nullptr){
            cur_prev->next = cur_next;//NOTE: may be nullptr
        }
        if(cur_next != nullptr){
            cur_next->prev = cur_prev;//NOTE: may be nullptr
        }
        
        //NOTE: finally, maintain head
        if(cur == head){
            head = cur_next;//NOTE: may be nullptr
        }
        
        delete cur;
        cur_size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
