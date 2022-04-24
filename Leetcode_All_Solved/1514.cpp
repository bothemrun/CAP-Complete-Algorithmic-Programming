#include<limits.h>
#include<queue>
#include<math.h>
#include<float.h>
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double,int>>> adjlist(n, vector<pair<double,int>>() );
        for(int i=0;i<(int)edges.size();i++){
            vector<int>& e = edges[i];
            adjlist[ e[0] ].push_back( { -log(succProb[i]), e[1]} );
            adjlist[ e[1] ].push_back( { -log(succProb[i]), e[0]} );
            //(weight, to_idx)
        }
        
        //NOTE: SPFA
        vector<double> d(n, DBL_MAX);//NOTE
        vector<bool> inqueue(n, false);
        d[start] = 0.0;
        inqueue[start] = true;
        queue<pair<double,int>> q;
        q.push( {d[start], start} );
        while(q.size() != 0){
            pair<double,int> u = q.front();
            q.pop();
            inqueue[u.second] = false;
            
            for(const pair<double,int>& v:adjlist[u.second]){
                if(d[v.second] > d[u.second] + v.first){
                    d[v.second] = d[u.second] + v.first;
                    
                    if(inqueue[v.second] == false){
                        q.push( {d[v.second], v.second} );
                        inqueue[v.second] = true;
                    }
                }
            }
        }
        
        if(d[end] == INT_MAX)return 0.0;
        return 1.0/exp(d[end]);
    }
};
