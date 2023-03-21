//m1
//O(f * nlogn), f == folder[i].length, optim from O(f * n^2) by trie.
// ascii code: '/' < alphabet
#include<algorithm>
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        //NOTE: utilizing ascii code: '/' < alphabet
        sort(folder.begin(), folder.end());

        vector<string> ans;
        string prev = folder.front();
        ans.push_back(folder.front());
        for(int i=1;i<folder.size();i++){
            //NOTE: folder[i].at(prev.size()) == '/' is crucial
            if( !(folder[i].find(prev) == 0 && folder[i].at(prev.size()) == '/' ) ){
                ans.push_back(folder[i]);
                prev = folder[i];
            }
        }
        return ans;
    }
};
