//m1

//optimization/maximize/minimize --> dp, greedy, binary search the answer

//O(n*log max_pos)

//1. then did some optimization for the binary range.
//O(n*log( max_pos / m ))
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
        int ball = 1;
        int last_put = pos.front();
        for(int i=1;i<n;i++){
            if(pos[i] - last_put >= dist_bound){
                if(++ball == m) return true;

                last_put = pos[i];
            }
        }

        return false;
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
