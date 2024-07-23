//m0

//[A] tree size = 2^30 = 1e9 too large MLE, must use binary tree's array indexing (actually as described)

//[B] for LCA, LCA by dfs takes O(n) for each query --> TLE.
//1. so must need binary lifting in O(logn) (preprocessing needs O(nlogn)).


//[C] similar to binary lifting.

//1. fact: nodes at the same level have the same most significant bit. --> just by actually calculating the indices.

//2. raise 1 of them to the same level by looking at the most significant bit.
//3. raise both of them until they are the same --> LCA.

//O(Q * logn) = O(1e5 * 30) = 3e6

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    inline int get_level(int val){
        int level = 0;
        while(val != 0){
            level++;

            val >>= 1;
        }
        return level;
    }

    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> ans(m);

        for(int q=0;q<m;q++){
            int a = queries[q][0];
            int b = queries[q][1];

            int level_a = get_level(a);
            int level_b = get_level(b);

            if(level_a > level_b){
                a >>= (level_a-level_b);
                assert(a > 0);
            }else if(level_a < level_b){
                b >>= (level_b-level_a);
                assert(b > 0);
            }

            int common = 0;
            while(a != b){
                common++;
                a >>= 1;
                b >>= 1;
            }

            ans[q] = common*2 + abs(level_a - level_b) + 1;
        }
        return ans;
    }
};
