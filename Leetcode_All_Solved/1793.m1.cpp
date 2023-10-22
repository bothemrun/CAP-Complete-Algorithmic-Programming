//m1
//O(n) monotonic stack for last / next smaller arrays

#define FRONT (-1)
#define BACK (n)

#include<algorithm>
#include<stack>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;

    inline void last_smaller_fn(const vector<int>& nums, const int& begin, const int& end, const int& delta, vector<int>& last_smaller){

        last_smaller.resize(n);

        int begin_all = (delta==1)? FRONT:BACK;

        stack<int> mono;
        for(int i=begin; delta*i <= delta*end ;i += delta){
            while(
                mono.size() &&
                !( nums[ mono.top() ] < nums[i] )
            ){
                mono.pop();
            }

            last_smaller[i] = (mono.size())? mono.top():begin_all;


            mono.push(i);
        }
    }

    int maximumScore(vector<int>& nums, int k) {
        n = nums.size();

        vector<int> last_smaller;
        last_smaller_fn(nums, 0, n-1, 1, last_smaller);

        vector<int> next_smaller;
        last_smaller_fn(nums, n-1, 0, -1, next_smaller);


        int ans = nums[k];
        for(int i=0;i<n;i++)if(
            last_smaller[i] < k &&
            next_smaller[i] > k
        ){
            ans = max(
                ans,
                nums[i] * ( next_smaller[i]-1 - last_smaller[i] )
            );
        }

        return ans;
    }
};
