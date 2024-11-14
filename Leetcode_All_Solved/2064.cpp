//m0
//binary search the answer, O(m log max_quantities)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    inline bool good(int n, const vector<int>& quan, const int bound){
        //edge case
        if(bound == 0) return false;

        for(const int& q: quan){
            n -= q/bound + (q%bound != 0);
            if(n<0) return false;
        }
        return n>=0;
    }
    int binary(const int n, const vector<int>& quan, int low, int high){
        int mid = (high-low)/2 + low;
        bool mid_res = good(n, quan, mid);
        if(mid_res==true && good(n, quan, mid-1)==false)
            return mid;
        assert(low != high);
        
        if(mid_res) return binary(n, quan, low, mid);
        else return binary(n, quan, mid+1, high);
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        return binary(n, quantities, 1, *max_element(quantities.begin(), quantities.end()) );
    }
};
