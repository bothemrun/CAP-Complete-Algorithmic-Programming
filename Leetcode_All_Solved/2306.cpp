//NOTE: group by first is better than group by suffix,
//NOTE: because O(26*26*n) better than O(n*n*26)
#define alphabet 26
#include<unordered_set>
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> first2suffix(alphabet);
        for(const string& s: ideas){
            first2suffix[ s.front() - 'a' ].insert( s.substr(1) );
            //ok with s.size() == 1
        }

        long long cnt = 0;
        for(int i=0;i<alphabet;i++){
            for(int j=i+1;j<alphabet;j++){
                
                int union_cnt = 0;
                for(const string& suffix: first2suffix[i]){
                    if( first2suffix[j].count(suffix) != 0) union_cnt++;
                }

                cnt += 2 * 
                ( first2suffix[i].size() - union_cnt) * 
                ( first2suffix[j].size() - union_cnt);
                //ok with 0 size, empty string
            }
        }

        return cnt;
    }
};
