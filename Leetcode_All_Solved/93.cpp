#include<string>
class Solution {
private:
    vector<string> ans;
    const int subnet_max_int = 255;
    inline bool valid(const string& s, int subnet_low, int len){
        string subnet = s.substr(subnet_low, len);
        if(len != 1 && subnet.at(0) == '0')return false;//leading 0, excluding 0 itself
        if(subnet_max_int < stoi(subnet) )return false;
        return true;
    }
    void dfs(const string& s, string ip="", int n_delim=0, int subnet_low=0){
        if(n_delim == 4 && subnet_low == s.size()){
            ans.push_back( ip.substr(0, ip.size() - 1) );
            return;
        }
        if(n_delim >= 5 || subnet_low > s.size()-1 )return;
        
        for(int len=1;len<=3;len++){
            int subnet_high = subnet_low + len - 1;
            if(subnet_high > s.size()-1)break;
            if(valid(s, subnet_low, len) == false)continue;
            
            dfs(s, ip + s.substr(subnet_low, len) + ".", n_delim + 1, subnet_high + 1);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        dfs(s);
        return ans;
    }
};
