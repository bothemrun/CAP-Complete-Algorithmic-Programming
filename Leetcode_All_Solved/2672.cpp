#include<assert.h>
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int> color(n, 0);
        vector<int> ans;
        int same = 0;
        for(int i=0;i<q;i++){
            //NOTE: color 0 doesn't count
            int idx = queries[i][0];
            int col = queries[i][1];
            
            if(col == color[idx]){
                //set the same color
                ans.push_back(same);//ok with old being 0, since col >= 1
                continue;
            }
            
            //remove old
            if(color[idx] != 0){
                //ok with neighbors being 0, already ruled out
                if(idx+1<n && color[idx+1] == color[idx]){
                    assert(color[idx+1] != 0);
                    same--;
                }
                if(idx-1>=0 && color[idx-1] == color[idx]){
                    assert(color[idx-1] != 0);
                    same--;
                }
            }//else: nothing to remove
            
            color[idx] = col;
            //add new
            //don't care about old color[idx] being 0 or not
            if(idx+1<n && color[idx+1] == color[idx]){
                assert(color[idx+1] != 0);
                same++;
            }
            if(idx-1>=0 && color[idx-1] == color[idx]){
                assert(color[idx-1] != 0);
                same++;
            }
            
            ans.push_back(same);
        }
        return ans;
    }
};
