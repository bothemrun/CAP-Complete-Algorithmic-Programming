//m1

//[A] as the time order i goes


//[B] utilize the fact that the painted are bool on/off states.
//1. so like two pointers, the traversal of all painted points are independent to i.

//2. use tree set to jump to next point still on. --> so no repeated visiting of points turned off.


//max_p := max_end - min_start = 5e4, P := max_p - min_p
//O(PlogP) + O(nlogP) + O(PlogP)

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        //in real testcases, 1200ms without this.
        int min_start = INT_MAX;
        int max_end = INT_MIN;
        for(const vector<int>& p: paint){
            min_start = min(min_start, p[0]);
            max_end = max(max_end, p[1]);
        }

        set<int> cur_on;
        for(int p=min_start;p<=max_end;p++){
            cur_on.insert(p);
        }


        int n = paint.size();
        vector<int> worklog(n, 0);
        
        for(int i=0;i<n;i++){
            int cnt = 0;

            auto cur = cur_on.lower_bound(paint[i][0]);
            while(cur != cur_on.end() && *cur < paint[i][1] ){
                cnt++;

                cur = cur_on.erase(cur); //jump to the next point currently on. --> no repeated visit
            }

            worklog[i] = cnt;
        }

        return worklog;
    }
};
