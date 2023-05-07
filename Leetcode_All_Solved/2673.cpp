#include<stdlib.h>
#include<algorithm>
#define COST(i) ( cost[ (i)-1 ] )
class Solution {
public:
    int increment = 0;
    int n;
    int postorder_pathsum(const vector<int>& cost, const int& root){
        if(root > n) return 0;//null
        int left = postorder_pathsum(cost, root*2);
        int right = postorder_pathsum(cost, root*2 + 1);
        increment += abs(left - right);
        return max(left, right) + COST(root);
    }
    int minIncrements(int n, vector<int>& cost) {
        this->n = n;
        postorder_pathsum(cost, 1);
        return increment;
    }
};
