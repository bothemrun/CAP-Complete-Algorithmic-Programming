#include<algorithm>
class Solution {
public:
    int n;
    bool search(const vector<int>& arr, int i, vector<bool>& visited){
        if(arr[i] == 0)return true;
        if(visited[i] == true)return false;
        
        visited[i] = true;
        int j = (-arr[i]);
        if( (0<=i+j && i+j<n) && search(arr, i+j, visited))return true;
        j = arr[i];
        if( (0<=i+j && i+j<n) && search(arr, i+j, visited))return true;
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        vector<bool> visited(n, false);
        return search(arr, start, visited);
    }
};
