class Solution {
private:
    vector<int> set;
    int set_find(const int& a){
        if(set[a] == (-1))return a;
        else return (set[a] = set_find(set[a]));
    }
    void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a != b)set[a] = b;
    }
    inline int set_count(){
        int cnt = 0;
        for(int i=0;i<set.size();i++)if(set[i] == (-1))cnt++;
        return cnt;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        set = vector<int>(n, (-1));
        for(int i=0;i<n;i++)for(int j=0;j<n;j++){
            if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                set_join(i, j);
            }
        }
        
        return n - set_count();
    }
};
