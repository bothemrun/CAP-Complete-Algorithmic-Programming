//1. the child from (0, 0) can only go with the main diagonal.
//2. other 2 children can't cross the main diagonal, or they can't make it to (n-1, n-1)
//O(n^2)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

#define inf_add(a, b) ( (a==impossible || b==impossible)? impossible:(a+b) )
class Solution {
public:
    int n;
    const int notyet = (-1);
    const int impossible = INT_MIN;
    vector<vector<int>> memo;
    int no_cross(const vector<vector<int>>& fruits, int i, int j){
        if(!( 0<=i && i<n && 0<=j && j<n )){
            return impossible;
        }
        if(i==j){
            return impossible;
        }
        if(i==0){
            if(j==n-1){
                return fruits[i][j];
            }else{
                return impossible;
            }
        }
        if(j==0){
            if(i==n-1){
                return fruits[i][j];
            }else{
                return impossible;
            }
        }
        if(memo[i][j] != notyet) return memo[i][j];
        
        int last;
        if(i<j){
            //upper right
            last = max({
                no_cross(fruits, i-1, j-1),
                no_cross(fruits, i-1, j),
                no_cross(fruits, i-1, j+1),
            });
        }else{
            last = max({
                no_cross(fruits, i-1, j-1),
                no_cross(fruits, i, j-1),
                no_cross(fruits, i+1, j-1),
            });
        }
        return memo[i][j] = inf_add( fruits[i][j], last );
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        this->n = fruits.size();
        memo.resize(n, vector<int>(n, notyet));
        
        int ans = no_cross(fruits, n-1, n-2);
        ans += no_cross(fruits, n-2, n-1);
        
        for(int i=0;i<n;i++){
            ans += fruits[i][i];
        }
        return ans;
    }
};
