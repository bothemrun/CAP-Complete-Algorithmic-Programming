#include<assert.h>
#include<unordered_map>
#include<unordered_set>
class Solution {
public:
    unordered_map<string, vector<string>> children;
    string lca;

    int lca_count(const string& root, unordered_set<string>& target_set){
        int cnt = 0;
        for(const string& child: children[root] ){
            int child_cnt = lca_count(child, target_set);
            cnt += child_cnt;

            //NOTE: already found
            if(child_cnt == target_set.size())return target_set.size();
        }

        cnt += ( target_set.count(root) != 0 );
        //NOTE: this is lca
        if(cnt == target_set.size()){
            lca = root;
            return target_set.size();
        }
        return cnt;
    }

    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        //get topmost root
        unordered_set<string> list_head;
        for(const vector<string>& region: regions){
            list_head.insert(region[0]);
        }

        for(const vector<string>& region: regions){
            for(int i=1;i<region.size();i++){
                list_head.erase( region[i] );//if not found, ok

                children[region[0]].push_back( region[i] );
            }
        }

        assert(list_head.size() == 1);
        string root = *( list_head.begin() );

        unordered_set<string> target_set;
        target_set.insert(region1);
        target_set.insert(region2);

        lca_count(root, target_set);
        return lca;
    }
};



