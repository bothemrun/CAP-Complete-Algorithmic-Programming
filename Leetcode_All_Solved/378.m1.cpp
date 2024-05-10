//m1
//O(nlog(max val)) = O(nlog10^9) = O(n*30) time
//O(1) space by binary search
//tricky for duplicates

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n, k;
    inline int smaller_cnt(const vector<vector<int>>& mat, const int bound){
        int cnt=0;
        int j=n-1;

        for(int i=0;i<n;i++){
            while(j>=0 && !( mat[i][j] <= bound ) ){
                j--;
            }

            if(j<0) break;

            cnt += j - (0-1);
        }

        return cnt;
    }
    int binary(const vector<vector<int>>& mat, int low, int high){
        int mid = low + (high-low)/2;

        int mid_cnt = smaller_cnt(mat, mid);
        //wrong: smaller(mid-1)==k-1, mid_cnt==k...
        //NOTE: duplicates
        if( smaller_cnt(mat, mid-1) < k && k <= mid_cnt )
            return mid;

        if(mid_cnt < k) return binary(mat, mid+1, high);
        else return binary(mat, low, mid);
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n = matrix.size();
        this->k = k;

        return binary(matrix, matrix[0][0], matrix[n-1][n-1]);
    }
};
