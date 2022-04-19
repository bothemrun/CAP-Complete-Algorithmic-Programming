#include<algorithm>
#include<unordered_map>
#include<utility>
class Solution {
private:
    static bool cmp_ptr(const pair<int,char>& p1, const pair<int,char>& p2){
        if(p1.first != p2.second)return p1.first > p2.first;
        else return p1.second < p2.second;
    }
public:
    string frequencySort(string s) {
        unordered_map<char,int> char2cnt;
        for(const char& c:s){
            auto it = char2cnt.find(c);
            if(it == char2cnt.end())char2cnt[c] = 1;
            else char2cnt[c]++;
        }
        
        vector<pair<int,char>> v;
        for(auto it = char2cnt.begin();it != char2cnt.end();it++)v.push_back( pair<int,char>(it->second, it->first) );
        sort(v.begin(), v.end(), cmp_ptr);
        
        string ans = "";
        for(auto p:v){
            for(int i=0;i<p.first;i++)ans+=p.second;
        }
        return ans;
    }
};
