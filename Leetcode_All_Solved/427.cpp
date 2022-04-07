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
    int n;
    Node* quad_tree(const vector<vector<int>>& grid, int low_i, int high_i, int low_j, int high_j, int& same_block){
        if(low_i == high_i && low_j == high_j){
            same_block = grid[low_i][low_j];
            return new Node( (grid[low_i][low_j] == 1)? true:false, true);
        }
        
        int mid_i = low_i + (high_i-low_i)/2;
        int mid_j = low_j + (high_j-low_j)/2;
        int block1, block2, block3, block4;
        Node* topleft = quad_tree(grid, low_i, mid_i, low_j, mid_j, block1);
        Node* topright = quad_tree(grid, low_i, mid_i, mid_j+1, high_j, block2);
        Node* bottomleft = quad_tree(grid, mid_i+1, high_i, low_j, mid_j, block3);
        Node* bottomright = quad_tree(grid, mid_i+1, high_i, mid_j+1, high_j, block4);
        if(block1 == block2 && block2 == block3 && block3 == block4 && block4 != 2){
            same_block = block1;
            return new Node( topleft->val, true);
        }else{
            same_block = 2;//not the same
            return new Node(true, false, topleft, topright, bottomleft, bottomright);
        }
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        n = grid.size();
        int same_block;
        return quad_tree(grid, 0, n-1, 0, n-1, same_block);
    }
};
