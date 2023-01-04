#include<unordered_map>
class Solution {
public:
    inline int div_ceiling(const int& a, const int& b){
        if(a%b == 0)return a/b;
        else return a/b + 1;
    }
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> diff2cnt;
        for(const int& t: tasks){
            if(diff2cnt.count(t) == 0)
                diff2cnt[t] = 1;
            else diff2cnt[t]++;
        }

        int round = 0;
        for(unordered_map<int,int>::iterator it = diff2cnt.begin();it != diff2cnt.end();it++){
            if(it->second == 1)return (-1);

            round += div_ceiling(it->second, 3);
        }
        return round;
    }
};
