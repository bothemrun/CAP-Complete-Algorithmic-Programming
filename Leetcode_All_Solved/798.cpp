//m0

//[A] the point to position relation is an non-decreasing spike.


//[B] adjust the spike to the rotation relative to nums[i]'s position:

//1. i < spike cut --> 00011110000
//2. spike cut < i --> 11100001111
//3. i == spike cut --> 100001111 --> the same as 2.
//3.a. i==n-1 == spike cut --> 10000000000


//[C] think in brute force:

//1. the superposition of [B] for all nums[i] --> loop for rotation k --> ans


//[D] to solve [C], use a difference array.

//1. diff[ i - (0-1) ] ]++  diff[ (i - (0-1)) + ((n-1) - (nums[i]-1) ) ]--
//2. diff[0]++  diff[ i - (nums[i]-1) ]--  diff[ i - (0-1) ]++

#define max_n ((int)1e5)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();

        //int diff[max_n] = {0};
        int diff[max_n + 1] = {0};

        for(int i=0;i<n;i++){
            if(i < nums[i]){
                diff[ i - (0-1) ]++; //1~n --> possibly out of bound

                diff[ (i - (0-1)) + ((n-1) - ( nums[i]-1 )) ]--; //(1~n) + (n - (0~(n-1)) ) = (1~n) + (n~1)
                //worried that == 2n ?? no!
                //since i < nums[i], the worst is i+1 == nums[i],
                //hence, the worst is n - 1 --> no out of bound
            }else{
                diff[0]++;
                diff[ i - (nums[i]-1) ]--;
                //since i >= nums[i],
                //(0~n-1) + 1 = 1~n --> possibly out of bound
                diff[ i - (0-1) ]++; //up to n --> possibly out of bound

                //conclusion for out of bound: worst up to n --> vector/array size to n+1
            }
        }

        int sweep = 0;//no int overflow
        int max_point = 0, max_k = 0;
        for(int k=0;k<n;k++){
            sweep += diff[k];

            if(sweep > max_point){
                max_point = sweep;
                max_k = k;
            }
        }

        return max_k;
    }
};
