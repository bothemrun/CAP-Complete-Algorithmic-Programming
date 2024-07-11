//m2

//[A] interval --> line sweep/diff array
//1. line sweep implemented by sorting


//[B] as the time order i
//1. for each i, we have to do 1 line sweep.
//2. n^2 TLE


//[C] think of it as Tetris: later i stacked upwards.
//1. many cut points for delta +1/-1.


//[D] many deltas at the same position
//1. use a map of position --> vector of deltas
//2. deploit all deltas of 1 position at a time.


//[E] tree set a the sweep, for the lowest Tetris block currently on.


//[F] how to get the duration?

//1. length between nearby cuts.
//2. next position in the map - this position.
//3. map.next must exist, since we must turn off the interval with end_i.


//[G] later block stacked lower:

//1. the tree set sweep cuts the duration.


//[H] later block stacked higher:

//1. the tree set sweep says the current block is still lower.
//2. still gives the cut duration to it.

//3. edge case: [0, 10] [1,2] [6,7] --> worklog[0] is pieced together from 5 contiguous cut intervals.


//[I] conclusion:

//1. similar to 218. The Skyline Problem

//2. O(nlogn)

//3. best idea: think in Tetris

#define t3i tuple<int,int,int>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

enum ON_OFF{
    ON,
    OFF
};

class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        int n = paint.size();

        vector<t3i> line_sweep(2*n);
        for(int i=0;i<n;i++){
            line_sweep[i*2] = t3i(paint[i][0], i, ON);
            //not paint[i][1] + 1
            line_sweep[i*2 + 1] = t3i(paint[i][1], i, OFF);
        }

        sort(line_sweep.begin(), line_sweep.end()); //on/off doesn't matter


        vector<int> worklog(n, 0);

        set<int> sweep_cur_on; //no dup

        int start=0, m = line_sweep.size();
        while(start<m){
            const auto [pos, _, __] = line_sweep[start];

            //go thru the same pos
            int end;
            for(end=start;end<m && get<0>(line_sweep[end]) == pos;end++){
                const auto [_, i, on_off] = line_sweep[end];

                if(on_off == ON){
                    sweep_cur_on.insert(i);
                }else{
                    sweep_cur_on.erase(sweep_cur_on.find(i));//although no dup
                }
            }

            //update
            start = end; //end already bad


            //pos is the front cut

            //trap: can't use "on_off" to check --> counterexample: [H].3.
            if(sweep_cur_on.size()){
                assert(end<m); //end already bad

                worklog[ *sweep_cur_on.begin() ] += get<0>(line_sweep[end]) - pos;
            }
        }

        return worklog;
    }
};

