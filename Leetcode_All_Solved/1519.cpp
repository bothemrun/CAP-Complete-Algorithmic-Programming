#include<unordered_map>
class Solution {
public:
    vector<vector<int>> adjlist;
    vector<int> ans;

    void postorder(const string& labels, const int& root, unordered_map<char,int>& char2cnt, const int& parent=(-1)){

        for(const int& child: adjlist[root])if(child != parent){
            unordered_map<char,int> child_cnt;
            postorder(labels, child, child_cnt, root);

            for(auto& [key, val]: child_cnt){
                if(char2cnt.count(key) == 0){
                    char2cnt[key] = val;
                }else{
                    char2cnt[key] += val;
                }
            }
        }//for child

        
        if(char2cnt.count(labels[root]) == 0){
            char2cnt[labels[root]] = 1;
        }else{
            char2cnt[labels[root]]++;
        }

        ans[root] = char2cnt[labels[root]];
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n);
        adjlist = vector<vector<int>>(n, vector<int>());
        for(const vector<int>& e: edges){
            adjlist[e[1]].push_back(e[0]);
            adjlist[e[0]].push_back(e[1]);
        }

        unordered_map<char,int> char2cnt;
        postorder(labels, 0, char2cnt);
        return ans;
    }
};



