//m0

//[A] interval --> line sweep/diff array


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

#define tii tuple<int,int>
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
        
        map<int, vector<tii> > line_sweep;
        for(int i=0;i<n;i++){
            line_sweep[ paint[i][0] ].push_back(tii(i, ON));
            line_sweep[ paint[i][1] ].push_back(tii(i, OFF));
        }


        vector<int> worklog(n, 0);

        set<int> sweep_cur_on;//no duplicate

        //turning the map into a map of pos --> vector of deltas is also ok.
        for(auto it=line_sweep.begin();it != line_sweep.end();it++){
            const auto& [pos, deltas] = *it;

            //processed all with the same pos at a time
            for(const auto& [i, on_off]: deltas){
                if(on_off == ON){
                    sweep_cur_on.insert(i);
                }else{
                    //erase(val) removes all instances with val
                    sweep_cur_on.erase(i);
                }
            }

            if(sweep_cur_on.size()){
                /*
                auto next_it = it;
                next_it++;
                assert( next_it != line_sweep.end() ); //ok
                */

                //assert( it+1 != line_sweep.end() ); //wrong

                assert( next(it) != line_sweep.end() ); //ok

                //the lowest Tetris block
                worklog[ *sweep_cur_on.begin() ] += next(it)->first - it->first;
            }
        }

        return worklog;
    }
};

