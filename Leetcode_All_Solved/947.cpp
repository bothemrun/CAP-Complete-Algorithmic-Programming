#include<unordered_map>
class Solution {
private:
    vector<int> set;
    int set_find(const int& a){
        if(set[a] == (-1))return a;
        else return (set[a] = set_find(set[a]));
    }
    void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a != b)set[a] = b;
    }
    inline int set_count(){
        int cnt = 0;
        for(int i=0;i<set.size();i++)if(set[i] == (-1))cnt++;
        return cnt;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        set = vector<int>(n, (-1));
        //NOTE: O(n) build graph, instead of O(n^2)
        unordered_map<int,vector<int>> row2stone, col2stone;
        for(int i=0;i<n;i++){
            int row = stones[i][0], col = stones[i][1];
            if(row2stone.count(row) == 0)row2stone[row] = vector<int>({i});
            else row2stone[row].push_back(i);
            
            if(col2stone.count(col) == 0)col2stone[col] = vector<int>({i});
            else col2stone[col].push_back(i);
        }
        
        for(unordered_map<int,vector<int>>::iterator it = row2stone.begin();it != row2stone.end();it++){
            if(it->second.size() >= 2){
                for(const int& stone:it->second)set_join(it->second.at(0), stone);
            }
        }
        for(unordered_map<int,vector<int>>::iterator it = col2stone.begin();it != col2stone.end();it++){
            if(it->second.size() >= 2){
                for(const int& stone:it->second)set_join(it->second.at(0), stone);
            }
        }
        
        return n - set_count();
    }
};
