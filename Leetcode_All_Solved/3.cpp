#include<utility>
#include<unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int maxl = 0, tmpl = 0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int>::iterator f = m.find(s.at(i));
            if(f != m.end()){
                int cut_id = f->second;
                for(int j=cut_id;j>=0;j--){
                    f = m.find(s.at(j));
                    if(f == m.end()) break;
                    if(cut_id < f->second) break;
                    
                    m.erase(f);
                    tmpl--;
                }
            }
            
            pair<char,int> p (s.at(i), i);
            m.insert(p);
            tmpl++;
            if(maxl < tmpl) maxl = tmpl;
        }
        
        return maxl;
    }
};
