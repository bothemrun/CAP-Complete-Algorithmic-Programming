#include<limits.h>
class Solution {
private:
    int K;
    int target;
    int high_max;
    inline int ext(const vector<int>& arr, const int& i){
        if(i < 0)return INT_MIN;
        if(i > high_max)return INT_MAX;
        return arr[i];
    }
    inline vector<int> closest(const vector<int>& arr, int mid){
        int front_i = mid, back_i = mid+1;
        for(int k=0;k<K;k++){
            if(front_i >= 0 && back_i <= high_max){
                if(target - arr[front_i] <= arr[back_i] - target) front_i--;
                else back_i++;
            }else if(front_i >= 0){
                front_i--;
            }else{
                back_i++;
            }
        }
        
        vector<int> ans;
        for(int i=front_i+1;i<back_i;i++)ans.push_back(arr.at(i) );
        return ans;
    }
    vector<int> binary(const vector<int>& arr, int low, int high){
        int mid = low + (high-low)/2;
        if(ext(arr,mid) <= target && target < ext(arr,mid+1))return closest(arr, mid);
        //impossible if(low == high)return 
        
        if(ext(arr,mid) > target)return binary(arr, low, mid);
        else return binary(arr, mid+1, high);
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        K = k, high_max = arr.size()-1;
        target = x;
        return binary(arr, (-1), arr.size()-1);
    }
};
