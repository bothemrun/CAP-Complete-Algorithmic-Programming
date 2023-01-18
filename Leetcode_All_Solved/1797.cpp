#include<unordered_map>
class AuthenticationManager {
public:
    int time2live;
    unordered_map<string, int> token2expire;
    AuthenticationManager(int timeToLive) {
        time2live = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        token2expire[tokenId] = currentTime + time2live;
    }
    
    void renew(string tokenId, int currentTime) {
        if(token2expire.count(tokenId) == 0)return;
        if(token2expire[tokenId] <= currentTime)return;
        token2expire[tokenId] = currentTime + time2live;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int cnt = 0;
        vector<string> del;
        for(auto& [token, expire]: token2expire){
            if(expire <= currentTime)
                del.push_back(token);
            else cnt++;
        }

        for(const string& d: del)
            token2expire.erase(d);
        return cnt;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
