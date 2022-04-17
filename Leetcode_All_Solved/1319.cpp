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
        for(const int& s:set)if(s == (-1))cnt++;
        return cnt;
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        set = vector<int>(n, (-1));
        
        int extra_cable = 0;
        for(const vector<int>& cable:connections){
            if(set_find(cable[0]) != set_find(cable[1]))
                set_join(cable[0], cable[1]);
            else extra_cable++;
        }
        
        int need_cable = set_count() - 1;
        if(need_cable <= extra_cable)return need_cable;
        else return (-1);
    }
};
