//O(mn + n^2) dp + greedy
class Solution {
public:
    int m, n;
    vector<vector<int>> memo;
    const int notyet = (-1);
    int choose_or_not(const vector<int>& nums1, vector< unordered_map<int, int> >& j2v2next, int i, int j ){
        if(i==m || j==n) return 0;
        
        if(memo[i][j] != notyet) return memo[i][j];
        
        int ret = choose_or_not(nums1, j2v2next, i+1, j);
        
        if(j2v2next[j].find( nums1[i] ) != j2v2next[j].end() ){
            ret = max(
                ret,
                1 + choose_or_not(nums1, j2v2next, i+1, j2v2next[j][ nums1[i] ] + 1 )
            );
        }
        return memo[i][j] = ret;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        
        vector< unordered_map<int, int> > j2v2next(n);
        unordered_map<int, int> suf_v2next;
        for(int j=n-1;j>=0;j--){
            suf_v2next[ nums2[j] ] = j;
            
            j2v2next[j] = suf_v2next;
        }
        
        memo.resize(m, vector<int>(n, notyet));
        return choose_or_not(nums1, j2v2next, 0, 0);
    }
};
