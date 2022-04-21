//m1
//union by rank (+ path compression)
//https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
//Kruskal's MST
#include<algorithm>
#include<stdlib.h>
#include<utility>
#define VV_VP 1 //0 1

class Solution {
private:
    int n;
#if VV_VP == 1
    vector< pair<int,pair<int,int>> > edge;
#elif VV_VP == 0
    vector<vector<int>> edge;
#endif
    inline void make_graph(const vector<vector<int>>& points){
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
#if VV_VP == 1
            edge.push_back( { abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]) , {i,j} } );
#elif VV_VP == 0
            edge.push_back( {abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]), i, j} );
#endif
        }
    }
    
#if VV_VP == 1
    static bool cmp_ptr(const pair<int,pair<int,int>>& e1, const pair<int,pair<int,int>>& e2){
        return e1.first < e2.first; //NOTE: strict weak ordering: e1[0] <= e2[0];
    }
#elif VV_VP == 0
    static bool cmp_ptr(const vector<int>& e1, const vector<int>& e2){
        return e1[0] < e2[0]; //NOTE: strict weak ordering: e1[0] <= e2[0];
    }
#endif
    
    vector<int> set;
    vector<int> rank;//NOTE: union by rank
    int set_find(const int& a){
        if(set.at(a) == (-1))return a;
        else return (set.at(a) = set_find(set.at(a)));
    }
    void set_join(int root1, int root2){
        //NOTE: union by rank + path compression
        if(rank[root1] < rank[root2]) set[root1] = root2;
        else if(rank[root1] > rank[root2]) set[root2] = root1;
        else{
            set[root1] = root2;
            rank[root2]++;
        }
        /*a = set_find(a);
        b = set_find(b);
        if(a != b)set.at(a) = b;*/
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        n = points.size();
        make_graph(points);
        
        //NOTE: kruskal's mst
        sort(edge.begin(), edge.end(), cmp_ptr);
        
        set = vector<int>(n, (-1));
        rank = vector<int>(n, 0);//NOTE: union by rank
        int mst = 0;
        int mst_cnt = 0;
        for(const auto& e:edge){
#if VV_VP == 1
            int root1 = set_find(e.second.first);//(e[1]);
            int root2 = set_find(e.second.second);//(e[2]);
#elif VV_VP == 0
            int root1 = set_find(e[1]);
            int root2 = set_find(e[2]);
#endif
            if(root1 != root2){
                set_join(root1, root2);
#if VV_VP == 1
                mst += e.first;//e[0];
#elif VV_VP == 0
                mst += e[0];
#endif
                
                if(++mst_cnt == n-1)break;//prune
            }
        }
        return mst;
    }
};
