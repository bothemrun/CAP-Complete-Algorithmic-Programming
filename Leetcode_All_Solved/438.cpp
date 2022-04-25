#include<unordered_map>
class Solution {
private:
    unordered_map<char,int> window_balance;
    inline void window_push(const char& c){
        auto it = window_balance.find(c);
        if(it == window_balance.end()) window_balance[c] = 1;
        else if( ++(it->second) == 0 )window_balance.erase(it);
    }
    inline void window_pop(const char& c){
        auto it = window_balance.find(c);
        if(it == window_balance.end()) window_balance[c] = (-1);
        else if( --(it->second) == 0 ) window_balance.erase(it);
    }
    inline bool anagram(){
        return window_balance.size() == 0;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        if(m < n)return vector<int>();
        
        for(int i=0;i<n;i++)window_pop(p[i]);
        for(int i=0;i<n;i++)window_push(s[i]);
        
        vector<int> ans;
        for(int low=0;low+n-1<m;low++){
            int high = low + n-1;
            if(anagram() == true)ans.push_back(low);
            
            //update window
            if(high+1 < m){
                window_pop(s[low]);
                window_push(s[high+1]);
            }
        }
        return ans;
    }
};
