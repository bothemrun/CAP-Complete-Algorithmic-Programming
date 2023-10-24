//O(n) bfs
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();

        queue<int> q;
        vector<bool> inq(n, false);
        q.push(id);
        inq[id] = true;
        
        int bfs_level = 0;
        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                int u = q.front();
                q.pop();

                for(const int& v: friends[u])if(inq[v] == false){
                    inq[v] = true;
                    q.push(v);
                }
            }

            if(++bfs_level == level) break;
        }

        if(bfs_level != level) return vector<string>();

        unordered_map<string, int> video2cnt;
        while(q.size()){
            for(const string& video: watchedVideos[ q.front() ] ){
                video2cnt[video]++;
            }

            q.pop();
        }

        vector<string> ans;
        for(const auto& [vid, cnt]: video2cnt)
            ans.push_back(vid);

        auto cmp = [&video2cnt](const string& a, const string& b){
            if(video2cnt[a] != video2cnt[b])
                return video2cnt[a] < video2cnt[b];
            else return a < b;
        };
        sort(ans.begin(), ans.end(), cmp);
        return ans;
    }
};
