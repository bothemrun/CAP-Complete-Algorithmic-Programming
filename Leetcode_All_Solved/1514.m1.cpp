//m1
#include<math.h>
#include<float.h>
#include<queue>
class cmp_class{
public:
    bool operator()(const pair<double,int>& p1, const pair<double,int>& p2){
        return p1.first > p2.first;//min heap for d[]
    }
};
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double,int>>> adjlist(n, vector<pair<double,int>>() );
        for(int i=0;i<(int)edges.size();i++){
            vector<int>& e = edges[i];
            adjlist[ e[0] ].push_back( { -log(succProb[i]) , e[1] } );
            adjlist[ e[1] ].push_back( { -log(succProb[i]) , e[0] } );
            //(weight, to_idx)
        }
        
        //NOTE: Dijkstra
        vector<double> d(n, DBL_MAX);//NOTE:
        vector<bool> popped(n, false);
        d[start] = 0.0;
        priority_queue< pair<double,int>, vector<pair<double,int>>, cmp_class > min_heap;
        min_heap.push( {d[start], start} );
        while(min_heap.size() != 0){
            pair<double,int> u = min_heap.top();
            min_heap.pop();
            popped[u.second] = true;
            
            for(const pair<double,int>& v:adjlist[u.second]){
                if(popped[v.second] == true)continue;
                
                if(d[v.second] > d[u.second] + v.first){
                    d[v.second] = d[u.second] + v.first;
                    
                    min_heap.push( {d[v.second], v.second} );
                }
            }
        }
        
        if(d[end] == INT_MAX)return 0;
        return 1.0/exp(d[end]);
    }
};
