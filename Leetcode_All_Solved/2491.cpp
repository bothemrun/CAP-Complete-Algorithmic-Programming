#include<unordered_map>
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long long sum_all = 0;
        unordered_map<int,int> skill2cnt;
        for(const int& s: skill){
            sum_all += s;
            
            if(skill2cnt.count(s) == 0) skill2cnt[s] = 1;
            else skill2cnt[s]++;
        }
        if(sum_all % (n/2) != 0)return (-1);
        long long sum1 = sum_all / (n/2);
        //cout << "f";
        
        long long sum_p = 0;
        while(skill2cnt.size() != 0){
            unordered_map<int,int>::iterator it1 = skill2cnt.begin();
            long long s1 = it1->first;
            if( --(it1->second) == 0 ) skill2cnt.erase(s1);
            
            long long s2 = sum1 - s1;
            if( skill2cnt.count(s2) == 0 )return (-1);
            if( --(skill2cnt[s2]) == 0 ) skill2cnt.erase(s2);
            
            sum_p += s1 * s2;
        }
        
        /*for(int i=0;i<(n/2);i++){
            long long s2 = sum1 - skill[i];
            if(skill2cnt.count(s2) == 0)return (-1);
            cout << skill[i] << " " << s2 << endl;
            
            if( --skill2cnt[skill[i]] == 0 ) skill2cnt.erase(skill[i]);
            if( --skill2cnt[s2] == 0 ) skill2cnt.erase(s2);
            sum_p += skill[i] * s2;
        }*/
        return sum_p;
    }
};
