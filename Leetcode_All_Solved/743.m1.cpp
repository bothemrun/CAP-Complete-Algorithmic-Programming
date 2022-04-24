//m1
#include<utility>
#include<limits.h>
#include<queue>
#include<algorithm>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjlist(n+1, vector<pair<int,int>>());
        for(const vector<int>& e:times)
            adjlist.at( e[0] ).push_back( {e[2], e[1]} );//(weight, to_idx)
        
        //NOTE: SPFA
        vector<int> d(n+1, INT_MAX);
        vector<bool> inqueue(n+1, false);
        queue<pair<int,int>> q;//(d[], node_idx)
        d[k] = 0;
        q.push( {d[k], k} );
        inqueue[k] = true;
        while(q.size() != 0){
            pair<int,int> u = q.front();
            q.pop();
            inqueue.at( u.second ) = false;
            
            for(const pair<int,int>& v:adjlist.at(u.second) ){
                if(d.at(v.second) > d.at(u.second) + v.first ){
                    d.at(v.second) = d.at(u.second) + v.first;
                    
                    if(inqueue.at(v.second) == false){
                        q.push( {d[v.second], v.second} );
                        inqueue.at(v.second) = true;
                    }
                }
            }
        }
        
        //max delay
        int max_delay = 0;
        for(int i=1;i<=n;i++){
            if(d[i] == INT_MAX)return (-1);
            max_delay = max(max_delay, d[i]);
        }
        return max_delay;
    }
};
