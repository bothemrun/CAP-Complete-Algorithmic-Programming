#include<assert.h>

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int sta_size = 0;
        int stream = 1;
        for(const int& tar: target){
            while(!(tar == stream)){
                assert(stream < tar);

                stream++;
                ans.push_back("Push");
                ans.push_back("Pop");
            }

            stream++;
            ans.push_back("Push");
        }

        return ans;
    }
};
