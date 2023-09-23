//O(n)
#define maxn 51

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        //fast init to 0 by array
        bool hash_a[maxn] = {0};
        bool hash_b[maxn] = {0};

        int common = 0;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            const int& a = A[i];
            const int& b = B[i];

            if(a == b){
                common += 1;
            }else{
                common += hash_a[b];
                common += hash_b[a];
            }

            hash_a[a] = true;
            hash_b[b] = true;

            ans[i] = common;
        }

        return ans;
    }
};
