#define max_n (500+1)
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> group;
        vector<vector<int>> size2group_queue(max_n);

        for(int i=0;i<n;i++){
            size2group_queue[ groupSizes[i] ].push_back(i);
            if( size2group_queue[ groupSizes[i] ].size() == groupSizes[i] ){
                group.push_back( size2group_queue[ groupSizes[i] ] );
                size2group_queue[ groupSizes[i] ].clear();
            }
        }

        return group;
    }
};
