//m0
//O(nlogn)

//[A] interval overlapping --> 1D line sweep along the y-axis


//[B] problem 1: the inflection point should be counted as 1, not 2

//1. y = [1, 2] up & [2, 1] down, at y=2.
//2. --> half closed/open interval
//3. y[i-1] closed, y[i] open
//3.a. --> if upwards, [ y[i] ] down by 0.5 (-1).
//3.b. if downwards, [ y[i] ] up by 0.5 (+1).

//4. y.back() shall be closed. (no adjusting in 3.)

//5. after the adjustment to open, no inversion of start & end, since real points differ by >= 2, larger than 0.5 adjustment.


//[C] problem 2: sweeping shall also consider non-integer y.

//1. --> y *= 2, odd y as ?.5 points.

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxIntersectionCount(vector<int>& y) {
        int n = y.size();

        map<int, int> line_sweep;
        for(int i=0;i+1<n;i++){
            int start = 2*y[i]; //closed

            int end = 2*y[i+1];
            //adjust to open
            if(i+1 != n-1){//last right end --> closed, no adjusting to open

                //3.a. --> if upwards, [ y[i] ] down by 0.5 (-1).
                //3.b. if downwards, [ y[i] ] up by 0.5 (+1).
                if(y[i] < y[i+1]){
                    end -= 1;
                }else{
                    end += 1;
                }
            }

            line_sweep[ min(start,end) ]++; //on
            line_sweep[ max(start,end) + 1 ]--; //off
        }


        int ans = 0;
        int sweep = 0;
        for(const auto& [pos, delta]: line_sweep){
            sweep += delta;

            ans = max(ans, sweep);
        }
        return ans;
    }
};
