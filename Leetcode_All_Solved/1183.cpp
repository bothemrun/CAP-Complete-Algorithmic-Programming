//m0

// [Complexity]
//let submatrix size = side * side := Size,
//then complexity = O(enumerate all cells of the submatrix + sorting the value obtained from the submatrix) =
//O(Size + Size log Size) = O(side^2 log side)



// [Greedy Proof 1]
// why translation of only 1 (top left) square doesn't have conflict?

// [A] translated square with no overlap
//(1) obvious. proved. but the [B], let's assume:
//(2) for an optimal configuration, choose the square with most points.
//(3) then copy that optimal square to all other squares.
//(4) so the crucial part is that: why not exceed maxOnes (conflict) for translated squares with overlap after (3) ?


// [B] translated square with overlap
//(1) since the squares are all copied from the optimal square, so they all the same.
//(2) now move it in only 1 direction with only 1 directional overlap (vertically or horizontally),
//(3) we can see that the translated and the un-translated part of the square together form the original square.
//(4) that is, we can cut and paste that translated part to form the original square.
//(5) so they are the same after the cut and paste
//(6) similarly for the translation of arbitray directions, we can cut and paste 3 translated parts.




// [Greedy Proof 2]
// now we put squares from the top left corner of the big matrix.
// so what about the remaining parts that don't fit perfectly with the square?

// [A] we have 4 shape parts of square to fill.
// (1) see official solution pictures for clarity.
// (2) first choose the intersection shape part, which is the top left shape part.
// (3) the choose the the left bottom and the top right shape parts in a sorted order.
// (4) finally the right bottom shape part is useless.




// [Reference]:
//1. official solution: great pictures

//2. hiteshgupta: https://leetcode.com/problems/maximum-number-of-ones/solutions/377033/c-o-1-solution-with-explanation-totally-intuitive/

//3. Simpleson: https://leetcode.com/problems/maximum-number-of-ones/solutions/376868/p-thon-o-1-solution/



#include<algorithm>

class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {

        
        vector<int> translated_square(sideLength * sideLength);

        int div1 = width / sideLength;
        int div2 = height / sideLength;
        int rem1 = width % sideLength;
        int rem2 = height % sideLength;

        for(int i=0;i<sideLength;i++)
            for(int j=0;j<sideLength;j++){
                translated_square[ i*sideLength + j ] =
                    div1 * div2 +
                    (i<rem1) * div2 +
                    (j<rem2) * div1 +
                    (i<rem1 && j<rem2) * 1;
            }
        
        auto cmp_lam = [](const int& a, const int& b){
            return a > b;//descending
        };
        sort(translated_square.begin(), translated_square.end(), cmp_lam);

        int sum = 0;
        for(int i=0;i<maxOnes;i++)
            sum += translated_square[i];
        return sum;
    }
};
