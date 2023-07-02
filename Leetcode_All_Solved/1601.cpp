//m0
//backtracking in O(2^requests * n) = O(2^16 * 20) = 1e6

#include<algorithm>

class Solution {
public:
    int max_allow = 0;
    void enum_backtrack(const vector<vector<int>>& requests, const int& i, vector<int>& net, const int& mask_size, const int& allow=0){
        if(i == mask_size){
            for(const int& x: net)if(x!=0) return;
            max_allow = max(max_allow, allow);
            return;
        }

        //choose or not
        enum_backtrack(requests, i+1, net, mask_size, allow);

        //ok for from == to
        net[requests[i][0]]--;
        net[requests[i][1]]++;
        enum_backtrack(requests, i+1, net, mask_size, allow + 1);
        net[requests[i][0]]++;
        net[requests[i][1]]--;
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int mask_size = requests.size();

        vector<int> net(n, 0);
        enum_backtrack(requests, 0, net, mask_size);
        return max_allow;
    }
};
