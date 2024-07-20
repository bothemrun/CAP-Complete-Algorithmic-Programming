//m1

//honestly, the intuition is hard to think of. here's my attempt:


//[A] longest common subsequence in O(mn) TLE.

//[B] another DP formulation: (i, j) where we can't skip target[j]

//1. similar to 727. Minimum Window Subsequence hard


//[C] From matching to comparing neighbors: 2 Sequence to 1.

//1. 'cuz target distinct, so in [B], we're actually matching arr with indices j=0,1,2,3,...

//2. we trying to go from 2 sequences to 1, to reduce the complexity.

//3. LCS --> longest ordered subsequence.


//[D] longest ordered subsequence --> LIS:

//1. reverse map value to idx.
//2. arr[i] not in target --> map to INT_MAX --> hence LIS ends.

//[E] LIS
//1. vanilla LIS DP in O(n^2) TLE.

//2. so need LIS(m) in O(mlogm) --> 
//a. 1964	Find the Longest Valid Obstacle Course at Each Position	hard
//b. 300	Longest Increasing Subsequence	medium.


//[F] from m0 to m1
//1. in m0, we use INT_MAX to represent numbers not in target, and we append 1 extra INT_MAX at the end.
//2. here just make another array.


//O(nlogn)

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    unordered_map<int,int> val2i;

    inline int LIS_tree(const vector<int>& nums){
        int max_lis = 0;
        vector<int> tree_arr;

        for(const int& x: nums){
            auto it = lower_bound(tree_arr.begin(), tree_arr.end(), x);

            int lis = 0;
            //if empty, v.begin() == v.end()
            if(it == tree_arr.end()){
                tree_arr.push_back(x);

                lis = tree_arr.size();
            }else{
                int j = it - tree_arr.begin();

                //the replacement is crucial
                *it = x;

                lis = j - (0-1);
            }

            max_lis = max(max_lis, lis);
        }
        return max_lis;
    }

    int minOperations(vector<int>& target, vector<int>& arr) {
        for(int i=0;i<(int)target.size();i++) val2i[target[i]] = i;

        vector<int> nums;
        for(const int& x: arr)if(val2i.count(x) != 0){
            nums.push_back(val2i[x]);
        }

        return (int)target.size() - LIS_tree(nums);
    }
};
