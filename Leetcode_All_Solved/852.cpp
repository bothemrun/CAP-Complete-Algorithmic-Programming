class Solution {
private:
    int binary(const vector<int>& arr, int low, int high){
        int mid = low + (high-low)/2;
        if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])return mid;
        
        if(arr[mid-1] >= arr[mid])return binary(arr, low, mid);
        else return binary(arr, mid+1, high);
    }
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        return binary(arr, 1, arr.size()-1-1);
    }
};
