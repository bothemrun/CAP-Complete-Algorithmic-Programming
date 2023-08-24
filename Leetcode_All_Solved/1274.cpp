//Quadtree

//divide & conquer into a Quadtree.
//the Quadtree has each point as the leaves.

//since at most 10 ships, so we traverse at most 10 paths from the Quadtree root to the leaf.
//the depth of the Quadtree is log4(mn)
//, so O(10 log4(mn) ) = O(10 * log4(1000 * 1000)) = O(100) visited nodes.
//for each node, we check 4 children, then the max API calls = O(4 * 10 * log4(mn) ) = O(400).

/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

#define V2(a, b) vector<int>( {a, b} )

class Solution {
public:
    int quadtree(Sea& sea, const vector<int>& bottomLeft, const vector<int>& topRight){

        const int& x1 = bottomLeft[0];
        const int& y1 = bottomLeft[1];
        const int& x2 = topRight[0];
        const int& y2 = topRight[1];

        //base case
        if(!(x1 <= x2 && y1 <= y2)) return 0;
        if(x1==x2 && y1==y2) return sea.hasShips(topRight, bottomLeft);
        if(sea.hasShips(topRight, bottomLeft) == false) return 0;
        
        int mid_x = x1 + (x2-x1)/2;
        int mid_y = y1 + (y2-y1)/2;

        int res = 0;
        res += quadtree(sea, V2(mid_x+1, mid_y+1), V2(x2, y2) );
        res += quadtree(sea, V2(x1, y1), V2(mid_x, mid_y) );
        res += quadtree(sea, V2(x1, mid_y+1), V2(mid_x, y2) );
        res += quadtree(sea, V2(mid_x+1, y1), V2(x2, mid_y) );

        return res;
    }

    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {

        return quadtree(sea, bottomLeft, topRight);
    }
};
