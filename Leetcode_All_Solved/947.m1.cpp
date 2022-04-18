//m1
#include<unordered_map>
class Solution {
private:
    vector<vector<int>> adjlist;
    vector<bool> visited;
    void dfs(int u){
        if(visited[u])return;
        visited[u] = true;
        for(const int& v:adjlist[u])dfs(v);
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int,vector<int>> row2stone, col2stone;
        for(int i=0;i<n;i++){
            int row = stones[i][0], col = stones[i][1];
            if(row2stone.count(row) == 0)row2stone[row] = vector<int>({i});
            else row2stone[row].push_back(i);
            if(col2stone.count(col) == 0)col2stone[col] = vector<int>({i});
            else col2stone[col].push_back(i);
        }
        
        adjlist = vector<vector<int>>(n, vector<int>());
        for(unordered_map<int,vector<int>>::iterator it = row2stone.begin();it != row2stone.end();it++){
            for(int i=1;i<it->second.size();i++){
                adjlist[it->second.at(0)].push_back(it->second.at(i));
                adjlist[it->second.at(i)].push_back(it->second.at(0));
            }
        }
        for(unordered_map<int,vector<int>>::iterator it = col2stone.begin();it != col2stone.end();it++){
            for(int i=1;i<it->second.size();i++){
                adjlist[it->second.at(0)].push_back(it->second.at(i));
                adjlist[it->second.at(i)].push_back(it->second.at(0));
            }
        }
        
        //dfs for #connected components
        int connected_component = 0;
        visited = vector<bool>(n, false);
        for(int i=0;i<n;i++)if(visited[i] == 0){
            dfs(i);
            connected_component++;
        }
        return n - connected_component;
    }
};
