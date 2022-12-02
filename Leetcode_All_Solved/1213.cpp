#include<algorithm>
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int i = 0, j = 0, k = 0;
        vector<int> merged;
        while(i < arr1.size() && j < arr2.size() && k < arr3.size()){
            int max3 = max(arr1[i], max(arr2[j], arr3[k]) );
            while(i < arr1.size() && arr1[i] < max3) i++;
            while(j < arr2.size() && arr2[j] < max3) j++;
            while(k < arr3.size() && arr3[k] < max3) k++;
            
            if(i < arr1.size() && j < arr2.size() && k < arr3.size() && arr1[i] == arr2[j] && arr2[j] == arr3[k] ){
                merged.push_back(arr1[i]);
                i++;
                j++;
                k++;
            }
        }
        return merged;
    }
};
