#include<algorithm>
class Solution {
private:
    static bool cmp_ptr(const int& a, const int& b){
        //return a > b;//min heap
        return a < b;//max heap
    }
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> prefix(m+1, vector<int>(n+1, 0));//dummy identity 0
        //NOTE: vector<int> min_heap_k;//NOTE: O(mnlogk), not O(mnlog(mn))
        vector<int> max_heap;//NOTE: if(k << mn) then lots of pop wasterd.
        for(int i=1;i<=m;i++)for(int j=1;j<=n;j++){
            //NOTE:xor: Abelian group. division is multiply: (A^B)^B = A due to B^B = 0(identity)
            prefix[i][j] = matrix[i-1][j-1] ^ prefix[i-1][j] ^ prefix[i][j-1] ^ prefix[i-1][j-1];
            //min_heap_k.push_back(prefix[i][j]); push_heap(min_heap_k.begin(), min_heap_k.end(), cmp_ptr);
            max_heap.push_back(prefix[i][j]); push_heap(max_heap.begin(), max_heap.end(), cmp_ptr);
            
            /*if(min_heap_k.size() > k){
                pop_heap(min_heap_k.begin(), min_heap_k.end(), cmp_ptr); min_heap_k.pop_back();
            }*/
        }
        
        for(int i=0;i<k-1;i++){
            pop_heap(max_heap.begin(), max_heap.end(), cmp_ptr); max_heap.pop_back();
        }
        return max_heap.front();
    }
};
