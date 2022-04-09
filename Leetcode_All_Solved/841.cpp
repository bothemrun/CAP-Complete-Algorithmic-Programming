class Solution {
private:
    vector<bool> visited;
    void dfs(const vector<vector<int>>& rooms, int u=0){
        if(visited.at(u))return;
        visited.at(u) = true;
        for(const int& v:rooms.at(u))dfs(rooms, v);
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited = vector<bool>(rooms.size(), false);
        dfs(rooms);
        for(int i=0;i<visited.size();i++)if(visited[i] == false)return false;
        return true;
    }
};
