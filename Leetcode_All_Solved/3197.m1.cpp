//m1
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

#define inf_add(x, y, z) ( (x==INT_MAX || y==INT_MAX || z==INT_MAX)? INT_MAX:(x + y + z) )

class Solution {
public:
    const int impossible = INT_MAX;

    inline int rec1(const vector<vector<int>>& grid, const int start_i, const int end_i, const int start_j, const int end_j){

        int min_i = INT_MAX;
        int max_i = INT_MIN;

        int min_j = INT_MAX;
        int max_j = INT_MIN;

        for(int i=start_i;i<=end_i;i++)
            for(int j=start_j;j<=end_j;j++)if(grid[i][j]){
                min_i = min(min_i, i);
                max_i = max(max_i, i);

                min_j = min(min_j, j);
                max_j = max(max_j, j);
            }
        
        if(min_i == INT_MAX) return impossible;
        return (max_i - (min_i-1)) * (max_j - (min_j-1));
    }

    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();

        int ans = INT_MAX;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                //horizontal split
                //1. upper has 1 rec
                ans = min(
                    ans,
                    inf_add(
                        rec1(grid, 0, i, 0, n-1),
                        rec1(grid, i+1, m-1, 0, j),
                        rec1(grid, i+1, m-1, j+1, n-1)
                    )
                );
                //2. lower has 1 rec
                ans = min(
                    ans,
                    inf_add(
                        rec1(grid, i+1, m-1, 0, n-1),
                        rec1(grid, 0, i, 0, j),
                        rec1(grid, 0, i, j+1, n-1)
                    )
                );


                //vertical split
                //1. left has 1 rec
                ans = min(
                    ans,
                    inf_add(
                        rec1(grid, 0, m-1, 0, j),
                        rec1(grid, 0, i, j+1, n-1),
                        rec1(grid, i+1, m-1, j+1, n-1)
                    )
                );
                //2. right has 1 rec
                ans = min(
                    ans,
                    inf_add(
                        rec1(grid, 0, m-1, j+1, n-1),
                        rec1(grid, 0, i, 0, j),
                        rec1(grid, i+1, m-1, 0, j)
                    )
                );
            }
        
        for(int i0=0;i0<m;i0++)
            for(int i1=i0+1;i1<m;i1++){
                ans = min(
                    ans,
                    inf_add(
                        rec1(grid, 0, i0, 0, n-1),
                        rec1(grid, i0+1, i1, 0, n-1),
                        rec1(grid, i1+1, m-1, 0, n-1)
                    )
                );
            }
        
        for(int j0=0;j0<n;j0++)
            for(int j1=j0+1;j1<n;j1++){
                ans = min(
                    ans,
                    inf_add(
                        rec1(grid, 0, m-1, 0, j0),
                        rec1(grid, 0, m-1, j0+1, j1),
                        rec1(grid, 0, m-1, j1+1, n-1)
                    )
                );
            }
        
        return ans;
    }
};
