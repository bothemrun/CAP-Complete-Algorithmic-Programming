#include<algorithm>
class BrowserHistory {
public:
    vector<string> history;
    int cur_page;
    int last_page;//NOTE: not the last entry of vector
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        cur_page = 0;
        last_page = 0;
    }
    
    void visit(string url) {
        cur_page++;
        if(cur_page == history.size()){
            history.push_back(url);
        }else history[cur_page] = url;
        last_page = cur_page;
    }
    
    string back(int steps) {
        cur_page = max(0, cur_page - steps);
        return history[cur_page];
    }
    
    string forward(int steps) {
        cur_page = min(last_page, cur_page + steps);
        return history[cur_page];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
