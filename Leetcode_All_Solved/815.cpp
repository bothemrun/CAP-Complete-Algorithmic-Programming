//1. graph connection on bus / stop groups.
//2. by building an inverse map from stop to bus index.
//3. if a stop has multiple group, then connect the groups.
//4. O(max #stop) * O(max #group) = O( sum(routes[i].length) ) * O(500) = O(5e7)

#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        //edge case
        if(source == target) return 0;


        unordered_map<int, vector<int>> stop2group;
        int m = routes.size();
        for(int i=0;i<m;i++){
            for(const int& stop: routes[i]){
                stop2group[stop].push_back(i);
                //no duplicate
            }
        }

        //adjacency list for groups
        vector<vector<int>> al(m);
        for(const auto& [stop, group_v]: stop2group){
            int n = group_v.size();
            if(n == 1) continue;

            for(int i=0;i<n;i++){
                al[ group_v[i] ].push_back( group_v[ (i+1)%n ] );
                al[ group_v[ (i+1)%n ] ].push_back( group_v[i] );
            }
        }

        //find the group of the target
        unordered_set<int> target_group;
        for(const int& group: stop2group[target]){
            target_group.insert(group);
        }


        //bfs on groups
        queue<int> q;
        vector<bool> inq(m, false);

        for(const int& group: stop2group[source]){
            q.push(group);
            inq[group] = true;
        }

        int level = 1;
        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                int group_u = q.front();
                q.pop();

                if(target_group.count(group_u) != 0)
                    return level;
                
                for(const int& group_v: al[group_u]){
                    if(inq[group_v] == true) continue;

                    inq[group_v] = true;
                    q.push(group_v);
                }
            }

            level++;
        }

        return (-1);
    }
};
