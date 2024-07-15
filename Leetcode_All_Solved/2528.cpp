//m0

//[A] binary search the answer

//[B] greedy: if i not sufficient, build new power stations at the right end of the window.

//O(n * log(sum + k) )
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    int r;
    long long k;

    inline bool good(vector<int> stations, const long long min_p){
        //spent extra O(n) to copy stations vector by value.

        long long window = 0;
        for(int t=0;t<r;t++){
            if( !( 0+t < n ) ) break;
            window += stations[0+t];
        }

        long long remain = k;
        for(int i=0;i<n;i++){
            int frontend = i-r;
            int backend = i+r;

            //update, add
            if(backend < n) window += stations[backend];

            if(window < min_p){
                long long deficit = min_p - window;

                if(remain < deficit ){
                    return false;
                }

                stations[ min(n-1, backend) ] += deficit;
                remain -= deficit;

                //update
                window += deficit;
            }
            
            //update, drop
            if(frontend>=0) window -= stations[frontend];
        }

        return true;
    }

    long long binary(const vector<int>& stations, long long low, long long high){
        long long mid = low + (high-low)/2LL;

        bool mid_res = good(stations, mid);
        if(mid_res==true && good(stations, mid+1)==false)
            return mid;
        
        if(mid_res==true)
            return binary(stations, mid+1, high);
        else
            return binary(stations, low, mid);
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        this->n = stations.size();
        this->r = r;
        this->k = k;

        long long sum = 0;
        for(const int& p: stations) sum += p;

        return binary(
            stations,
            *min_element(stations.begin(), stations.end()),
            k + sum
        );
    }
};
