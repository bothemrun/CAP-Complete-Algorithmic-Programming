//O(n)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        int n = candies.size();

        unordered_map<int,int> cnt;
        for(const int& candy: candies) cnt[candy]++;

        //make the 1st window
        int flavor = cnt.size();
        for(int i=0;i<k-1;i++){
            if( --cnt[ candies[i] ] == 0){
                flavor--;
            }
        }

        //edge case
        if(k-1<0) return flavor;

        int ans = 0;
        for(int i=k-1;i<n;i++){
            //add
            if( --cnt[ candies[i] ] == 0){
                flavor--;
            }

            ans = max(ans, flavor);

            //drop
            int left = i - (k-1);
            if( ++cnt[ candies[left] ] == 1){
                flavor++;
            }
        }
        return ans;
    }
};
