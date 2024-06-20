//m0

//optimization/maximize/minimize --> dp, greedy, binary search the answer

//O(n*log max_pos * log n)

//1. then did some optimization for the binary range.
//O(n*log( max_pos / m ) * logn)
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n, m;
    inline bool good(const vector<int>& pos, const int dist_bound){
        //greedy: the 1st ball must be in the 1st basket
        int i=0;//index of current basket with a ball in
        for(int ball=1;ball<m;ball++){
            int j = lower_bound(
                pos.begin() + i,
                pos.end(),
                pos[i] + dist_bound
            ) - pos.begin();

            if(!(j<n)) return false;

            i = j;
        }

        return true;
    }

    int binary_ans(const vector<int>& pos, int low, int high){
        int mid = low + (high-low)/2;

        bool mid_res = good(pos, mid);
        if(mid_res==true && good(pos, mid+1)==false)
            return mid;
        
        if(mid_res==true)
            return binary_ans(pos, mid+1, high);
        else
            return binary_ans(pos, low, mid);
    }
    int maxDistance(vector<int>& position, int m) {
        this->n = position.size();
        this->m = m;

        sort(position.begin(), position.end());

        //return binary_ans(position, 1, max_pos);
        return binary_ans(position, 1, ( position.back() - position.front() ) / (m-1) + 1 );
    }
};
