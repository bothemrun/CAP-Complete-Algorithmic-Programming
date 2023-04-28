//m2
//space optim bottom up dp
#define IDX(i) ((i)%2)
#define Memo(i) (memo[ IDX(i) ])
#define max_len 500
#include<algorithm>
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int memo[2][max_len+1] = {0};//fast init

        //i=0 init
        for(int i=1;i<=m;i++){
            //j=0 init
            
            for(int j=1;j<=n;j++){
                //NOTE: all nums/strings 0-indexed
                if(nums1[i-1] == nums2[j-1])
                    Memo(i)[j] = 1 + Memo(i-1)[j-1];
                else Memo(i)[j] = max(
                    Memo(i)[j-1],
                    Memo(i-1)[j]
                );
            }
        }

        return Memo(m)[n];
    }
};
