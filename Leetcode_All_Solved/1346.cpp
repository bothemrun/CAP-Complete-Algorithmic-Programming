#include<algorithm>
class Solution {
private:
    bool binary(const vector<int>& arr, const int& target, int low, int high){
        if(low > high)return false;
        int mid = low + (high-low)/2;
        if(arr[mid] == target)return true;
        if(low == high)return false;
        
        if(arr[mid] < target)return binary(arr, target, mid+1, high);
        else return binary(arr, target, low, mid);
    }
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for(int i=0;i<arr.size();i++){
            if(arr[i] < 0){
                if(binary(arr,2*arr[i],0,i-1))return true;
            }else{//NOTE: for 2*0 == 0, must i+1, not i
                if(binary(arr,2*arr[i],i+1,arr.size()-1))return true;
            }
        }
        return false;
    }
};
