class Solution {
    int n;
    int set_find(vector<int>& set, int a){
        if(set[a] == (-1))return a;
        return (set[a] = set_find(set, set[a]));
    }
    void set_join(vector<int>& set, int a, int b){
        a = set_find(set, a);
        b = set_find(set, b);
        if(a != b) set[a] = b;
    }
    inline int n_set(const vector<int>& set){
        int ans = 0;
        for(int root:set)if(root == (-1))ans++;
        return ans;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<int> set(n, (-1));
        
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(isConnected[i][j])
            set_join(set,i,j);
        return n_set(set);
    }
};
