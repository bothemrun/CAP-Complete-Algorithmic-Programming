/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* dummy = new PolyNode();
        PolyNode* cur = dummy;
        while(poly1 != nullptr && poly2 != nullptr){
            if(poly1->power == poly2->power){
                int coef = poly1->coefficient + poly2->coefficient;
                if(coef != 0)
                    cur->next = new PolyNode(coef, poly1->power);
                
                poly1 = poly1->next;
                poly2 = poly2->next;
            }else if(poly1->power > poly2->power){
                cur->next = new PolyNode(poly1->coefficient, poly1->power);
                poly1 = poly1->next;
            }else{
                cur->next = new PolyNode(poly2->coefficient, poly2->power);
                poly2 = poly2->next;
            }
            //NOTE: in the case of sum of coef == 0
            if(cur->next != nullptr) cur = cur->next;
        }
        
        if(poly1 == nullptr) cur->next = poly2;
        if(poly2 == nullptr) cur->next = poly1;
        
        return dummy->next;
    }
};
