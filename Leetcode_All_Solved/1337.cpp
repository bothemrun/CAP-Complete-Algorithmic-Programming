#include<assert.h>
#include<algorithm>

bool cmp_fn(const pair<int,int>& a, const pair<int,int>& b){
    if(a.first == b.first)return a.second < b.second;
    else return a.first < b.first;
}

class Solution {
public:
    int m, n;

    inline bool good(const vector<int>& row, const int& i, const int& target){
        if(!(0<=i && i<n))return false;
        return row[i] == target;
    }

    int binary_high(const vector<int>& row, const int& low, const int& high, const int& target){
        int mid = low + (high-low)/2;
        if(good(row, mid, target) &&
            good(row, mid+1, target) == false)
            return mid;
        
        //NOTE: included low == high
        if(low == high){
            assert(low == 0 && row[low] == 0);
            return (-1);
        }

        if(good(row, mid, target))
            return binary_high(row, mid+1, high, target);
        else return binary_high(row, low, mid, target);
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        m = mat.size();
        n = mat.back().size();
        vector<pair<int,int>> cnt2idx(m);
        for(int i=0;i<m;i++){
            int cnt1 = 1 + binary_high(mat[i], 0, n-1, 1);
            cnt2idx[i] = pair<int,int>(cnt1, i);
            //cout << cnt1 << endl;
        }

        sort(cnt2idx.begin(), cnt2idx.end(), cmp_fn);
        vector<int> ans(k);
        for(int i=0;i<k;i++)
            ans[i] = cnt2idx[i].second;
        return ans;
    }
};
