/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
 #include<unordered_set>
 #include<queue>
class Solution {
public:
    inline string get_host(const string& s){
        int i;
        for(i=7;i<s.size();i++)if(s[i] == '/')return s.substr(7, i-1 - 6);
        return s.substr(7, i-1 - 6);
    }

    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        //NOTE: dfs too deep, use bfs

        string host = get_host(startUrl);
        vector<string> same_host;

        queue<string> q;
        q.push(startUrl);
        unordered_set<string> visited;

        while(q.size() != 0){
            int level_size = q.size();
            for(int i=0;i<level_size;i++){
                string node = q.front();
                q.pop();
                visited.insert(node);
                same_host.push_back(node);

                for(const string& link: htmlParser.getUrls(node) ){
                    if(visited.count(link) != 0) continue;
                    visited.insert(link);//also insert urls not under the same host
                    if(host != get_host(link) ) continue;

                    q.push(link);
                }
            }
        }

        return same_host;
    }

    //NOTE: dfs too deep
    /*
    vector<string> same_host;
    unordered_set<string> visited;
    inline string get_host(const string& s){
        int i;
        for(i=7;i<s.size();i++)if(s[i] == '/')return s.substr(7, i-1 - 6);
        return s.substr(7, i-1 - 6);
    }
    void dfs(const string& cur, HtmlParser htmlParser, const string& host){
        if(visited.count(cur) != 0)return;
        visited.insert(cur);

        if(host == get_host(cur)){
            same_host.push_back(cur);
            
            for(const string& link: htmlParser.getUrls(cur) ){
                dfs(link, htmlParser, host);
            }
        }
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        dfs(startUrl, htmlParser, get_host(startUrl) );
        return same_host;
    }
    */
};



