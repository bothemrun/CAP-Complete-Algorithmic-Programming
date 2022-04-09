//m1
//union find
class Solution {
private:
    int set_find(vector<int>& set, int a){
        if(set[a] == (-1))return a;
        else return (set[a] = set_find(set, set[a]));
    }
    bool set_join(vector<int>& set, int a, int b){
        a = set_find(set, a);
        b = set_find(set, b);
        if(a == b)return true;
        set[a] = b;
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> set(n, (-1));
        vector<int> ans;
        for(const vector<int>& e:edges)if(set_join(set, e[0]-1, e[1]-1) == true)ans = e;//NOTE: 1 to 0-based
        return ans;
    }
};
