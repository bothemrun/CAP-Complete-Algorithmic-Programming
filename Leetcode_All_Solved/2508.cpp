#include<unordered_set>
//bool adjmat[(int)(1e5+1)][(int)(1e5+1)] = {0};
//bool adjmat[(int)(1e5+1)][(int)(1e5+1)];
//bool adjmat[100002][100002];
class Solution {
public:
    //bool adjmat[(int)(1e5+1)][(int)(1e5+1)] = {0};
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> degree(n+1, 0);//NOTE: 1-indexed, 0 not used
        //vector<vector<bool>> adjmat(n+1, vector<bool>(n+1, false));
        //bool adjmat[(int)(1e5+1)][(int)(1e5+1)] = {0};

        for(const vector<int>& edge:edges){
            degree[ edge[0] ]++;
            degree[ edge[1] ]++;
            /*adjmat[ edge[0] ][ edge[1] ] = true;
            adjmat[ edge[1] ][ edge[0] ] = true;*/
        }
        

        int odd_degree = 0;
        vector<int> odd;
        //vector<vector<bool>> adjmat(odd_degree+1, vector<bool>(n+1, false));
        //cout << "mat size: " << adjmat.size() << " " << adjmat.back().size()<<endl;

        for(int i=1;i<=n;i++){//NOTE: 1~n
            if(degree[i]%2 == 1){
                odd_degree++;
                odd.push_back(i);
            }
            if(odd_degree > 4)return false;
        }
        //cout << odd_degree << " odd_degree\n";

        vector<vector<bool>> adjmat(odd_degree+1, vector<bool>(n+1, false));
        
        unordered_map<int, int> odd_map;
        for(int i=0;i<odd.size();i++){
            odd_map[ odd[i] ] = i;
            //printf("odd_map:%d %d\n", odd[i], i);
        }
        //cout << "de\n";

        for(const vector<int>& edge: edges){
            //printf("edge: %d %d\n", edge[0], edge[1]);
            if( odd_map.count(edge[0]) != 0 ){
                //printf("edge %d after odd_map %d\n", edge[0], odd_map[ edge[0] ] );
                adjmat[ odd_map[ edge[0] ] ][ edge[1] ] = true;
            }

            if( odd_map.count(edge[1]) != 0 ){
                //printf("meow edge %d after odd_map %d\n", edge[1], odd_map[ edge[1] ] );
                adjmat[ odd_map[ edge[1] ] ][ edge[0] ] = true;
                //cout << "de heree?\n";
            }

            //printf("end of edge: %d %d\n", edge[0], edge[1]);
        }
        //cout << "de2\n";
        
        if(odd_degree == 0)return true;
        if(odd_degree%2 == 1)return false;
        if(odd_degree == 2){
            //cout << "here?\n";
            
            //if(adjmat[ odd[0] ][ odd[1] ] == false)return true;
            if(adjmat[ 0 ][ odd[1] ] == false)return true;

            //NOTE: trap
            for(int i=1;i<=n;i++)if(i != odd[0] && i != odd[1]){
                //if(adjmat[ i ][ odd[0] ] == false && adjmat[ i ][ odd[1] ] == false)
                if(adjmat[ 0 ][ i ] == false && adjmat[ 1 ][ i ] == false)
                    return true;
            }
            return false;
            
            /*if(n >= 3)return true;//NOTE: trap
            else if(adjmat[ odd[0] ][ odd[1] ] == true)return false;
            else return true;*/
        }
        if(odd_degree == 4){
            //for(int i=0;i<3;i++)if(adjmat[ odd[3] ][ odd[i] ] == false){
            for(int i=0;i<3;i++)if(adjmat[ 3 ][ odd[i] ] == false){
                //if(adjmat[ odd[(i+1)%3] ][ odd[(i+2)%3] ] == false)return true;
                if(adjmat[ (i+1)%3 ][ odd[(i+2)%3] ] == false)return true;
            }
            return false;
            
            /*for(int i=0;i<4;i++){
                int i_connect = 0;
                for(int j=1;j<=3;j++){
                    if( adjmat[ odd[i] ][ odd[(i+j)%4] ] ){
                        i_connect++;
                    }
                }
                if(i_connect == 3)return false;
            }
            return true;*/
        }
        return false;
    }
};
