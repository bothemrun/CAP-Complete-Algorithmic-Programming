class Solution {
public:
    vector<vector<int>> adjlist;
    int cnt = 0;
    bool sub_has_apple_post(vector<bool>& hasApple, const int& root, const int& parent=(-1)){
        bool sub_has = hasApple[root];
        for(const int& child: adjlist[root])if(child != parent){
            bool child_has = sub_has_apple_post(hasApple, child, root);
            
            if(child_has) cnt += 2;

            sub_has |= child_has;
        }
        return sub_has;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adjlist = vector<vector<int>>(n, vector<int>());
        for(const vector<int>& e: edges){
            adjlist[e[0]].push_back(e[1]);
            adjlist[e[1]].push_back(e[0]);
        }

        sub_has_apple_post(hasApple, 0);
        return cnt;
    }
};
