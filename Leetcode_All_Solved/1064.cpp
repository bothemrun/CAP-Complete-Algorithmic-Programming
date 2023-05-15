//NOTE: properties: index diff by 1, arr[i] value diff by >= 1
#define good(i) ( (i>=0)? ( arr[i]==i ):false )   //ok for mid==0 & mid-1
class Solution {
public:
    int binary(const vector<int>& arr, const int& low, const int& high){
        int mid = low + (high-low)/2;
        
        //NOTE: since arr strictly ascending, once bad, then arr[i] can't match i
        if( good(mid) && !good(mid-1) )
            return mid;
        if(low == high) return (-1);

        //NOTE: arr[i] decreases by >= 1, while index decreases by 1.
        if( arr[mid] > mid || good(mid) )
            return binary(arr, low, mid);
        else //NOTE: arr[mid] < mid
            return binary(arr, mid+1, high);
        //NOTE: arr[mid] decreases by >= 1, so once index too large, index can't catch up with its decrease being 1.
    }
    int fixedPoint(vector<int>& arr) {
        int n = arr.size();
        return binary(arr, 0, n-1);
    }
};
