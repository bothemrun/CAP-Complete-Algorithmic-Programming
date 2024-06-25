//[no proof for the existence of a split in all other solutions]:



//[A] Proof: Must Exist 1 Split Having 1 & 2 Rectangles:

//1. must cover the leftmost point.
//2. so for the 1st rectangle := R1, 1 edge fixed.


//3. [case 2] R1 not at the corner  (of the smallest 1 covering as in 3195):

//3.a. to cover all points, R2 & R3 must be at the top & bottom sides of R1. --> 2 splits.


//4. [case 1] R1 at the corner:

//4.a. to prevent R1 being split, other 2 recs must be at the right & top sides of R1.
//4.b. R2 & R3 can't share the top right corner without being split.



//[B] Dimension Reduction --> Enumerate the Splits:

//1. proof in [A] applies to 1~3 rectangles.

//2.a. counterexample of 4 rectangle --> 
//2.b. see picture in lee215 solution: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/

//3. so recursively split 3 & 2 rectangles, and then solve the 1 rectangle problem by leetcode 3195.



//[C] Complexity O(n^4)

//1. 3 rectangles split to 2 in O(n) --> 2 split to 1 in O(n) --> 3195. takes O(n^2).



//[D] Intuition For [A] --> Dimension Reduction in 2D:

//1. think of the 2 rectangle problem.
//2. enumerate a horizontal or vertical split between the 2 rectangles. O(n^3)

#define inf_add(x, y) ( (x==INT_MAX || y==INT_MAX)? INT_MAX:(x + y) )

class Solution {
public:
    int m, n;
    const int impossible = INT_MAX;

    inline int area_1_rec(const vector<vector<int>>& grid, const int left, const int right, const int top, const int bottom){
        int min_i = INT_MAX;
        int max_i = INT_MIN;

        int min_j = INT_MAX;
        int max_j = INT_MIN;

        for(int i=left;i<=right;i++)
            for(int j=top;j<=bottom;j++)if(grid[i][j]){
                min_i = min(min_i, i);
                max_i = max(max_i, i);

                min_j = min(min_j, j);
                max_j = max(max_j, j);
            }
        
        if(min_i == INT_MAX) return impossible;
        return (max_i - (min_i-1)) * (max_j - (min_j-1));
    }

    int split(const vector<vector<int>>& grid, const int left, const int right, const int top, const int bottom, const int rec){

        if(rec==1) return area_1_rec(grid, left, right, top, bottom);

        int ret = INT_MAX;

        //horizontal split
        for(int i=left;i+1<=right;i++){
            //upper has 1 rec
            ret = min(
                ret,
                inf_add(
                    split(grid, left, i, top, bottom, 1),
                    split(grid, i+1, right, top, bottom, rec-1)
                )
            );

            //lower has 1 rec
            ret = min(
                ret,
                inf_add(
                    split(grid, left, i, top, bottom, rec-1),
                    split(grid, i+1, right, top, bottom, 1)
                )
            );
        }//for i

        //vertical split
        for(int j=top;j+1<=bottom;j++){
            //left part has 1 rec
            ret = min(
                ret,
                inf_add(
                    split(grid, left, right, top, j, 1),
                    split(grid, left, right, j+1, bottom, rec-1)
                )
            );

            //right part has 1 rec
            ret = min(
                ret,
                inf_add(
                    split(grid, left, right, top, j, rec-1),
                    split(grid, left, right, j+1, bottom, 1)
                )
            );
        }//for j

        return ret;
    }

    int minimumSum(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid.back().size();

        return split(grid, 0, m-1, 0, n-1, 3);
    }
};
