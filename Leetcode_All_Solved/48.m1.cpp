//m1
//O(1) space, clear logic.
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int ring=n, corner=0;ring>=2;ring -= 2, corner++){
            //top row of the ring / the displacement for the corner
            for(int tr=0;tr<ring-1;tr++){
                int side1 = (ring-1) - tr; //longer
                int side2 = tr - 0; //shorter
                //top left
                int tl_i = corner, tl_j = corner + tr;
                int tl = matrix[tl_i][tl_j];

                matrix[tl_i][tl_j] = matrix[tl_i + side1][tl_j - side2];
                matrix[tl_i + side1][tl_j - side2] = matrix[(tl_i + side1) + side2][(tl_j - side2) + side1];
                matrix[(tl_i + side1) + side2][(tl_j - side2) + side1] = matrix[tl_i + side2][tl_j + side1];
                matrix[tl_i + side2][tl_j + side1] = tl;
            }
        }
    }
};