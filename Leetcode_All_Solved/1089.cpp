#include<queue>
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(arr[i]);
            if(arr[i] == 0) q.push(arr[i]);

            arr[i] = q.front();
            q.pop();
        }
    }
};
