/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */
#include<assert.h>
class Solution {
public:
    int binary(ArrayReader& reader, const int& low, const int& high){
        if(low == high)return low;
        assert(low < high);

        int len = high - (low-1);
        int mid = low + (high-low)/2;
        if(len%2 == 0){
            int comp = reader.compareSub(low, mid, mid+1, high);
            
            if(comp == 1)return binary(reader, low, mid);
            else if(comp == (-1))return binary(reader, mid+1, high);
            else assert(false);
        }else{
            int comp = reader.compareSub(low, mid-1, mid+1, high);

            if(comp == 1)return binary(reader, low, mid-1);
            else if(comp == (-1))return binary(reader, mid+1, high);
            else return mid;
        }
    }
    int getIndex(ArrayReader &reader) {
        int n = reader.length();
        return binary(reader, 0, n-1);
    }
};
