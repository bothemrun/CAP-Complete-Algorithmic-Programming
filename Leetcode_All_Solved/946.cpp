#include<stack>
#include<assert.h>
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> sta;
        int i=0, j=0;
        while(i<n || j<n){
            if(sta.size() != 0 && j<n && sta.top() == popped[j]){
                sta.pop();
                j++;
            }else if(i<n) sta.push(pushed[i++]);
            else return false;
        }

        if(j==n) assert(sta.size() == 0);
        return i==n && j==n;
    }
};
