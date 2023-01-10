#include<unordered_map>
class Solution {
public:
    int cnt = 0;
    inline int encode(const int& a, const int& b){
        return 10*a + b;
    }
    void backtrack(unordered_map<int,int>& cross, vector<bool>& used, const int& m, const int& n, int used_cnt=0, int pre=0){
        if(used_cnt > n)return;
        if(used_cnt >= m)cnt++;

        for(int i=1;i<=9;i++)if(used[i] == false){
            if(cross.count(encode(pre, i)) != 0 &&
            used[ cross[encode(pre, i)] ] == false) continue;

            used[i] = true;
            backtrack(cross, used, m, n, used_cnt + 1, i);
            used[i] = false;
        }
    }
    int numberOfPatterns(int m, int n) {
        unordered_map<int,int> cross;
        int key = 1;
        for(int i=0;i<3;i++){
            cross[encode(key,key+2)] = key+1;
            cross[encode(key+2,key)] = key+1;
            key += 3;
        }        
        key = 1;
        for(int j=0;j<3;j++){
            cross[encode(key, key+3*2)]  = key+3*1;
            cross[encode(key+3*2, key)] = key+3*1;
            key++;
        }
        cross[encode(1,9)] = 5;
        cross[encode(9,1)] = 5;
        cross[encode(3,7)] = 5;
        cross[encode(7,3)] = 5;

        vector<bool> used(9+1, false);
        backtrack(cross, used, m, n);

        return cnt;
    }
};
