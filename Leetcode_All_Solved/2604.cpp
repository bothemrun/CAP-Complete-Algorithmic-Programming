//m0

//[A] time >= ans: ok, time < ans: can't --> binary seach turns optimization into checking feasibility


//[B] greedy: if h1<h2 g1<g2, then optimal to eat according to their relative order.

//1. fix the grains, hens have 5 cases.
//2. symmetric, so actually 3 cases.
//3. watch the overlaps in a graphical way.


//[C] for hen0: strategies:

//1. back & forth
//2. forth & back

//3. greedy part: see which strategy has the most net moves forward.


//[D]
//1. move hen index forward accordingly.


//[E] binary bound:
//1. extreme condition: only 1 hen:
//a. hen outside the grain range: any(grain or hen) max - any min
//b. hen inside the grain range: 1.5 * grain max - min


//[F] extreme case: 

//1. hens on the far right of grains.
//1.a. if the currently leftmost hen can't eat the leftmost grain, no other hens can.

//2. if this hen too far away leftwards. 
//2.a. for grain i, can give up this hen


//[G] decision tree:

/*
(a) lefmost remaining grain on hen's left:
    (a.1) eat it.  by 2 strategies:
        (a.1.1) back & forth
        (a.1.2) forth & back
    (a.2) can't eat it. no other hens can. return false.

(b) lefmost remaining grain on hen's right:
    (b.1) eat it.
    (b.2) can't eat it. give up this hen. don't return false.
*/


//reference: walkccc's implementation is better than wisdompeak / top 1 sol.
//O(sort)

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n, m;

    inline bool good(const vector<int>& hens, const vector<int>& grains, const int time){
        //edge case
        if(time<0) return false;

        int i=0; //uneaten grain idx
        for(const int& hen: hens){

            //net moves forward:
            int forward;

            //case 1: no grain on hen's left
            if(hen <= grains[i]){
                if(hen + time < grains[i]){
                    //return false;

                    //hen far away on the left, give up this hen.
                    continue;
                }

                forward = time; //>=0
            }else{
                //case 2: 1 grain on hen's left
                const int diff = hen - grains[i];

                if(diff > time) return false;

                //strategy 1: back & forth
                //bf may be <= 0
                int back_forth = time - 2*diff; //no overflow

                //strategy 2: forth & back
                //2*fb + diff = time
                //fb = (time - diff)/2 >= 0
                int forth_back = (time - diff)/2;

                //no clipping to 0, 'cuz diff <= time
                forward = max(back_forth, forth_back); // >= 0
            }

            //eaten leftmost grain in both cases, otherwise already returned false.
            //this shall be before the while loop!!!
            //wrong: i = max(i, i+1);
            i++;

            //increase i to uncovered grain
            //assert(forward>=0);
            while(i<m && hen + forward >= grains[i]){
                i++;
            }

            //eaten leftmost grain in both cases, otherwise already returned false.
            //wrong: i = max(i, i+1);

            if(i==m) return true;
        }
        return false;
    }

    int binary(const vector<int>& hens, const vector<int>& grains, int low, int high){

        int mid = low + (high-low)/2;
        bool mid_res = good(hens, grains, mid);
        if(mid_res==true && good(hens, grains, mid-1)==false)
            return mid;
        
        if(mid_res==true) return binary(hens, grains, low, mid);
        else return binary(hens, grains, mid+1, high);
    }

    int minimumTime(vector<int>& hens, vector<int>& grains) {
        n = hens.size();
        m = grains.size();

        sort(hens.begin(), hens.end());
        sort(grains.begin(), grains.end());

        int ma = max( hens.back(), grains.back() );
        int mi = min( hens.front(), grains.front() );

        return binary(
            hens, grains,
            0,
            (int)( 1.5 * (ma-mi) + 20 )
        );
    }
};
