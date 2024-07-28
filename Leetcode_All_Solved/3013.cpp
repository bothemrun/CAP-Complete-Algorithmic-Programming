//m0
//more general template with balance().

//dual multiset for top k.

//multiset.count() --> TLE. 'cuz it actually counts.

//O(n log dist)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    multiset<int> chosen, candidate;
    int chosen_k;//k-1
    long long window_sum = 0;

    inline void insert(const int& val){
        window_sum += val;
        chosen.insert(val);
    }
    inline void erase_chosen(const int& val){
        window_sum -= val;
        //erase(val) erases all instances
        chosen.erase(chosen.find(val));
    }
    inline void erase(const int& val){
        //multiset.count() --> TLE
        if(chosen.find(val) != chosen.end()){
            erase_chosen(val);
        }else{
            candidate.erase( candidate.find(val) );
        }
    }

    inline void balance(){
        while(chosen.size() > chosen_k){
            int val = *chosen.rbegin();

            erase_chosen(val);

            candidate.insert(val);
        }
        while(chosen.size() < chosen_k && candidate.size()){
            int val = *candidate.begin();

            candidate.erase(candidate.begin());

            insert(val);
        }

        //crucial swapping
        while(chosen.size() && candidate.size() && *chosen.rbegin() > *candidate.begin()){
            int cho = *chosen.rbegin();
            int can = *candidate.begin();

            erase_chosen(cho);
            candidate.erase(candidate.begin());

            insert(can);
            candidate.insert(cho);
        }
    }

    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        chosen_k = k-1;

        //make the 1st semi-window
        for(int i=1;i<=1+dist - 1;i++){
            insert(nums[i]);
        }

        long long min_sum = LLONG_MAX;
        for(int i=1;i<n;i++){
            int j = i+dist;
            if(!(j<n)) break;

            insert(nums[j]);//update

            balance();
            min_sum = min(min_sum, window_sum);

            erase(nums[i]);//update
        }
        return min_sum + nums.front();
    }
};
