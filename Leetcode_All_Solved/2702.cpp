//m0

//[A] minimize/maximize --> dp/greedy/binary search the answer

//[B] if above some values: ok, below: not ok --> binary search the answer


//[C] efficient way to check feasibility:

//1. since we have the number of operations, don't run a priority queue of currently max elements.


//O(n * log( max_nums ) ) = O(nlog1e9) = O(n*9)

#define ceil_div(a, b) ( a/b + ( (a%b==0)? 0:1 ) )
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int x, y;
    inline bool good(const vector<int>& nums, const int op){
        //edge case
        if(op<0) return false;

        const long long offset = (long long)y*(long long)op; //y*op;
        long long diff = x-y;
        long long remain = op;

        for(long long num: nums){
            num -= offset;
            if(num <= 0) continue;

            //diff != 0, x>y
            long long need_op = ceil_div(num, diff);
            if(need_op > remain) return false;
            remain -= need_op;
        }
        return true;
    }

    int binary(const vector<int>& nums, int low, int high){
        int mid = low + (high-low)/2;
        bool mid_res = good(nums, mid);
        if(mid_res==true && good(nums, mid-1)==false)
            return mid;
        
        if(mid_res==true)
            return binary(nums, low, mid);
        else
            return binary(nums, mid+1, high);
    }

    int minOperations(vector<int>& nums, int x, int y) {
        this->x = x;
        this->y = y;

        return binary(
            nums,
            0,
            *max_element(nums.begin(), nums.end())
        );
            
            //since the max element is changing, have to use a priority queue.
        /*
            ceil_div(
                *max_element(nums.begin(), nums.end()),
                x
            )
        );
        */
    }
};
