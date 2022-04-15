//m1
//https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
//NTU CSIE ADA Course
#include<stack>
class Solution {
private:
    int n;
    vector<vector<int>> adjlist;
    
    stack<int> s;
    vector<int> state;//NOTE: undiscovered, in recursion stack, all its outgoing nodes finished
    
    inline void make_graph(const vector<vector<int>>& edges){
        adjlist = vector<vector<int>>(n, vector<int>());
        for(const vector<int>& ab:edges)adjlist[ab[1]].push_back(ab[0]);
    }
    
    bool dfs(int u){
        state[u] = 1;
        for(const int& v:adjlist[u]){
            if(state[v] == 0 && dfs(v) == false)return false;
            if(state[v] == 1)return false;
        }
        state[u] = 2;
        s.push(u);//NOTE: must be after visiting outgoing
        return true;
    }
    
    inline vector<int> topo_sort(){
        state = vector<int>(n, 0);
        for(int i=0;i<n;i++)if(state[i] == 0){
            if(dfs(i) == false)return vector<int>();
        }
        
        //acyclic
        vector<int> topo;
        while(s.size() != 0){
            topo.push_back(s.top());
            s.pop();
        }
        return topo;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //NOTE: DAG Topological Sort. by DFS.
        n = numCourses;
        make_graph(prerequisites);
        
        return topo_sort();
    }
};
