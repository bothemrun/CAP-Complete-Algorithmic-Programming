//m1
//https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
//NTU CSIE ADA Course
class Solution {
private:
    int n;
    vector<vector<int>> adjlist;
    vector<int> state;//NOTE: undiscovered, in recursion stack, all of its outgoing nodes finished
    
    inline void make_graph(const vector<vector<int>>& edges){
        adjlist = vector<vector<int>>(n, vector<int>());
        for(const vector<int>& ab:edges)adjlist[ ab[1] ].push_back( ab[0] );
    }
    
    bool dfs(int u){
        state[u] = 1;
        for(const int& v:adjlist[u]){
            if(state[v] == 0 && dfs(v) == false)return false;
            if(state[v] == 1)return false;
        }
        state[u] = 2;
        return true;
    }
    
    inline bool acyclic(){
        state = vector<int>(n, 0);
        for(int i=0;i<n;i++)if(state[i] == 0){
            if(dfs(i) == false)return false;
        }
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //NOTE: DAG. by DFS. is acyclic
        n = numCourses;
        make_graph(prerequisites);
        
        return acyclic();
    }
};
