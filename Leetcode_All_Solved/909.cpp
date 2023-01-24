#include<unordered_map>
#include<queue>
#include<algorithm>
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int k = 1;
        unordered_map<int,int> jump;
        for(int i=n-1;i>=0;i--){
            if( (n-1 - i)%2 == 0 ){
                for(int j=0;j<n;j++){
                    if(board[i][j] != (-1))
                        jump[k] = board[i][j];
                    k++;
                }
            }else{
                for(int j=n-1;j>=0;j--){
                    if(board[i][j] != (-1))
                        jump[k] = board[i][j];
                    k++;
                }
            }
        }


        queue<int> q;
        vector<bool> instack(n*n + 1, false);
        q.push(1);
        instack[1] = true;

        int level = 0;
        while(q.size() != 0){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                int cur = q.front();
                q.pop();
                if(cur == n*n)return level;

                for(int next = cur+1;next<=min(cur+6, n*n);next++){
                    int destination = next;
                    if(jump.count(next) != 0)
                        destination = jump[next];
                    
                    if(instack[destination] == true)continue;

                    q.push(destination);
                    instack[destination] = true;
                }
            }

            level++;
        }

        return (-1);
    }
};
