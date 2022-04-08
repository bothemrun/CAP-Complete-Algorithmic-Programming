/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    Node* quad_or(Node* q1, Node* q2){
        if(q1->isLeaf && q2->isLeaf){
            if(q1->val || q2->val)return new Node(true, true);
            else return new Node(false, true);
        }else if(q1->isLeaf){
            if(q1->val == true)return new Node(true, true);
            return q2;
        }else if(q2->isLeaf){
            if(q2->val == true)return new Node(true, true);
            return q1;
        }
        
        Node* b1 = quad_or(q1->topLeft, q2->topLeft);
        Node* b2 = quad_or(q1->topRight, q2->topRight);
        Node* b3 = quad_or(q1->bottomLeft, q2->bottomLeft);
        Node* b4 = quad_or(q1->bottomRight, q2->bottomRight);
        if(b1->isLeaf &&
           b2->isLeaf &&
           b3->isLeaf &&
           b4->isLeaf){
            if(b1->val &&
               b2->val &&
               b3->val &&
               b4->val)return new Node(true, true);
            if(!b1->val &&
               !b2->val &&
               !b3->val &&
               !b4->val)return new Node(false, true);
        }
        
        return new Node(false, false, b1, b2, b3, b4);
    }
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        return quad_or(quadTree1, quadTree2);
    }
};
