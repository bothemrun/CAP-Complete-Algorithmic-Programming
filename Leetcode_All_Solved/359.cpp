#include<unordered_map>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Logger {
public:
    unordered_map<string, int> msg2bantime;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(
            msg2bantime.count(message) == 0 ||
            msg2bantime[message] <= timestamp
        ){
            msg2bantime[message] = timestamp + 10;
            return true;
        }else return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
