class Solution {
private:
    unordered_map<char,int> balance;
    inline void window_push(const char& c){
        auto it = balance.find(c);
        if(it == balance.end())balance[c] = 1;
        else if( ++(it->second) == 0 )balance.erase(it);
    }
    inline void window_pop(const char& c){
        auto it = balance.find(c);
        if(it == balance.end())balance[c] = (-1);
        else if( --(it->second) == 0 )balance.erase(it);
    }
    inline bool balanced(){
        return balance.size() == 0;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if(m > n)return false;
        
        //NOTE: key: negative balance
        for(int i=0;i<m;i++)window_pop(s1[i]);
        for(int i=0;i<m;i++)window_push(s2[i]);
        
        for(int low=0;low+ m-1<n;low++){
            int high = low + m-1;
            if(balanced()) return true;
            
            //update window
            if(high+1 < n){
                window_pop(s2[low]);
                window_push(s2[high+1]);
            }
        }
        return false;
    }
};
