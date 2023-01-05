class Solution {
public:
    int m, n;
    vector<vector< vector<pair<int,int>> >> adjlist;

    bool dfs(const int& i, const int& j, const int& dest_i, const int& dest_j, vector<vector<bool>>& visited){
        if(visited[i][j] == true)return false;
        visited[i][j] = true;

        if(i == dest_i && j == dest_j)return true;

        for(const pair<int,int>& p: adjlist[i][j]){
            if(dfs(p.first, p.second, dest_i, dest_j, visited) == true)return true;
        }
        return false;
    }

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size();
        n = maze.back().size();
        adjlist = vector<vector< vector<pair<int,int>> >>(m, vector< vector<pair<int,int>> >(n, vector<pair<int,int>>() ) );

        for(int i=0;i<m;i++){
            int j = 0;
            while(j < n){
                //find starting 0
                while(j < n && maze[i][j] == 1){
                    j++;
                }
                int start0 = j;

                //find ending 0
                while(j+1 < n && maze[i][j+1] == 0){
                    j++;
                }//now j may be n-1
                int end0 = j;

                if(start0 != end0){
                    adjlist[i][start0].push_back( pair<int,int>(i, end0) );
                    adjlist[i][end0].push_back( pair<int,int>(i, start0) );
                }


                //NOTE:
                if(start0 + 2 <= end0){
                    for(int k=start0+1;k<end0;k++){
                        adjlist[i][k].push_back( pair<int,int>(i, start0) );
                        adjlist[i][k].push_back( pair<int,int>(i, end0) );
                    }
                }


                //find next consecutive 0
                j++;
            }//while
        }


        for(int j=0;j<n;j++){
            int i = 0;
            while(i < m){
                //find starting 0
                while(i < m && maze[i][j] == 1){
                    i++;
                }
                int start0 = i;

                //find ending 0
                while(i + 1 < m && maze[i+1][j] == 0){
                    i++;
                }
                int end0 = i;

                if(start0 != end0){
                    adjlist[start0][j].push_back( pair<int,int>(end0, j) );
                    adjlist[end0][j].push_back( pair<int,int>(start0, j) );
                }


                //NOTE:
                if(start0 + 2 <= end0){
                    for(int k=start0+1;k<end0;k++){
                        adjlist[k][j].push_back( pair<int,int>(start0, j) );
                        adjlist[k][j].push_back( pair<int,int>(end0, j) );
                    }
                }


                //find next consecutive 0
                i++;
            }//while
        }


        vector<vector<bool>> visited(m, vector<bool>(n, false) );
        return dfs(start[0], start[1], destination[0], destination[1], visited);
    }
};



