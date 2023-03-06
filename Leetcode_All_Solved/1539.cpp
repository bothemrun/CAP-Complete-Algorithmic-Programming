#include<limits.h>
class Solution {
public:
    int n;
    inline int padding(const vector<int>& arr, const int& i){
        if(i == (-1))return 0;
        else if(i == n)return INT_MAX;
        else return arr[i];
    }
    inline int missing(const vector<int>& arr, const int& i){
        //NOTE: ok for i==(-1) & i==n
        return padding(arr, i)-1 - i;
    }
    int binary_padding(const vector<int>& arr, const int& k, const int& low, const int& high){
        int mid = (high-low)/2 + low;
        if(
            missing(arr, mid) < k &&
            k <= missing(arr, mid+1)
        ) return padding(arr, mid) + k - missing(arr, mid);
        //NOTE: ok for mid==(-1), won't have mid==n

        if(missing(arr, mid) < k)
            return binary_padding(arr, k, mid+1, high);
        else return binary_padding(arr, k, low, mid);
    }
    int findKthPositive(vector<int>& arr, int k) {
        n = arr.size();
        return binary_padding(arr, k, (-1), n);
    }
};
