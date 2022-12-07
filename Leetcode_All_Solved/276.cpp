struct nonconse3{
    int nonconse;//[i].nonconse = (k-1)*[i-1].nonconse + (k-1)*[i-1].conse2
    int conse2;//[i].conse2 = [i-1].nonconse
    //NOTE: but init: [0] = {k, 0}
    //NOTE: works for k == 1, for n == 1, respectively
};
class Solution {
public:
    int numWays(int n, int k) {
        vector<struct nonconse3> dp_seen(n);
        struct nonconse3 nc0 = {k, 0};//NOTE
        dp_seen[0] = nc0;
        for(int i=1;i<n;i++){
            int nonconse = (k-1) * dp_seen[i-1].nonconse + (k-1) * dp_seen[i-1].conse2;
            int conse2 = dp_seen[i-1].nonconse;
            struct nonconse3 nci = {nonconse, conse2};
            dp_seen[i] = nci;
        }
        
        //return max(dp_seen.back().nonconse, dp_seen.back().conse2);
        return dp_seen.back().nonconse + dp_seen.back().conse2;
        //NOTE: also works for n == 1
    }
};
