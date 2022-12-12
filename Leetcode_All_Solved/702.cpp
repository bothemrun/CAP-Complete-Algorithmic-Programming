/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    //NOTE: (1 << 31) is saved as a int, not long long, so integer overflow
    //const long long out = (1 << 31) - 1;
    const long long out = (long long)(1 << 31) - 1;
    int binary(const ArrayReader& reader, const int& target, int low, int high){
        int mid = low + (high-low)/2;
        int read_mid = reader.get(mid);
        if(read_mid == target)return mid;
        //included low == high

        //NOTE: includes both normal case and out of bound
        if(low == high)return (-1);//not found


        //NOTE: unusual case: out of bound
        int read_low = reader.get(low);
        if(read_low == out) return (-1);

        //NOTE: unusual case: out of bound
        if(read_mid == out)
            return binary(reader, target, low, mid-1);

        if(target < read_mid)
            return binary(reader, target, low, mid);
        else return binary(reader, target, mid+1, high);
    }
    int search(const ArrayReader& reader, int target) {
        return binary(reader, target, 0, 1e4 + 1);
    }
};
