#include<utility>
#include<assert.h>
#include<algorithm>
#include<unordered_map>
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> char2last_idx;
        
        int max_len = 0;
        int low = 0;
        for(int high=0;high<s.size();high++){
            if( !( char2last_idx.count(s[high]) != 0 || 
                char2last_idx.size() <= 1 ) ){
                /*unordered_map<char, int>::iterator it1 = char2last_idx.begin();
                unordered_map<char, int>::iterator it2 = it1+1;

                if(it1->second < it2->second){
                    low = it1->second + 1;
                }else if(it1->second > it2->second){
                    low = it2->second + 1;
                }else assert(false);*/

                vector<pair<char,int>> ci;
                for(auto it = char2last_idx.begin();it != char2last_idx.end();it++){
                    ci.push_back( pair<char,int>(it->first, it->second) );
                }

                if(ci[0].second < ci[1].second){
                    low = ci[0].second + 1;
                    char2last_idx.erase(ci[0].first);
                }else if(ci[0].second > ci[1].second){
                    low = ci[1].second + 1;
                    char2last_idx.erase(ci[1].first);
                }else assert(false);
            }

            char2last_idx[s[high]] = high;

            max_len = max(max_len, high - (low-1) );
        }

        return max_len;
    }
};
