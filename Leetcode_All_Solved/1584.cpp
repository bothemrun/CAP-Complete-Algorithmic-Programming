//Kruskal's MST
#include<algorithm>
#include<stdlib.h>
class Solution {
private:
    int n;
    vector<vector<int>> edge;
    inline void make_graph(const vector<vector<int>>& points){
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)
            edge.push_back( vector<int>({abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]), i, j}) );
    }
    static bool cmp_ptr(const vector<int>& e1, const vector<int>& e2){
        return e1[0] < e2[0]; //NOTE: strict weak ordering: e1[0] <= e2[0];
    }
    
    vector<int> set;
    int set_find(const int& a){
        if(set.at(a) == (-1))return a;
        else return (set.at(a) = set_find(set.at(a)));
    }
    void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a != b)set.at(a) = b;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        n = points.size();
        make_graph(points);
        
        //NOTE: kruskal's mst
        sort(edge.begin(), edge.end(), cmp_ptr);
        set = vector<int>(n, (-1));
        int mst = 0;
        int mst_cnt = 0;
        for(const vector<int>& e:edge){
            if(set_find(e[1]) != set_find(e[2])){
                set_join(e[1], e[2]);
                mst += e[0];
                
                if(++mst_cnt == n-1)break;//prune
            }
        }
        return mst;
    }
};
