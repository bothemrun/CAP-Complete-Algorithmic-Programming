/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */
#include<limits.h>
class Solution {
public:
    int lowerbound(BinaryMatrix& binaryMatrix, const int& i, const int& low, const int& high, const int& target){
        int mid = low + (high-low)/2;
        int ele_mid = binaryMatrix.get(i, mid);
        if( ele_mid == target &&
            ( mid-1<0 || binaryMatrix.get(i, mid-1) != target ) )
            return mid;
        //NOTE: includes low == high
        if(low == high)return INT_MAX;//not found

        if(ele_mid == target)
            return lowerbound(binaryMatrix, i, low, mid, target);
        else return lowerbound(binaryMatrix, i, mid+1, high, target);
    }
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> mn = binaryMatrix.dimensions();
        int m = mn[0];
        int n = mn[1];

        int first_1col = INT_MAX;
        for(int i=0;i<m;i++){
            first_1col = min(first_1col, lowerbound(binaryMatrix, i, 0, n-1, 1) );
        }
        return (first_1col == INT_MAX)? (-1):first_1col;
    }
};



