#include<utility>
#include<limits.h>
#include<queue>
#include<algorithm>
class cmp_class{
public:
    bool operator()(const pair<int,int>& p1, const pair<int,int>& p2){
        return p1.first > p2.first;//min heap of d[]
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjlist(n+1, vector<pair<int,int>>());
        for(const vector<int>& e:times)
            adjlist[ e[0] ].push_back( {e[2], e[1]} );//(weight, to_idx)
        
        //NOTE: Dijkstra
        vector<int> d(n+1, INT_MAX);
        vector<bool> popped(n+1, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp_class > pq;//(d[], node_idx)
        d[k] = 0;
        pq.push( {d[k], k} );
        while(pq.size() != 0){
            pair<int,int> u = pq.top();
            pq.pop();
            popped.at( u.second ) = true;
            
            for(const pair<int,int>& v:adjlist.at( u.second )){
                if(popped.at( v.second ) == true)continue;
                
                if( d.at(v.second) > d.at(u.second) + v.first ){
                    d.at(v.second) = d.at(u.second) + v.first;
                    pq.push( {d.at(v.second), v.second} );
                }
            }
        }
        
        //max delay time
        int max_delay = 0;
        for(int i=1;i<=n;i++){
            if(d[i] == INT_MAX)return (-1);
            max_delay = max(max_delay, d[i]);
        }
        return max_delay;
    }
};
