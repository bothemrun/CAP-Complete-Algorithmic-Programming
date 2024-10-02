#define max_k ((int)1e5)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        int r2cnt[max_k] = {0};
        for(const int& x: arr) r2cnt[ (x%k + k)%k ]++;

        for(int r=0;r<k;r++){
            int r2 = (k - r)%k;
            if(r > r2) break;

            if(r == r2){
                //edge case
                if(r2cnt[r]%2 == 1) return false;
            }else{
                if(r2cnt[r] != r2cnt[r2]) return false;
            }
        }
        return true;
    }
};
