#include<queue>
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> max_heap_k;
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0;i<m;i++)for(int j=0;j<n;j++){
            max_heap_k.push(matrix[i][j]);
            if(max_heap_k.size() > k) max_heap_k.pop();
        }
        return max_heap_k.top();
    }
};
