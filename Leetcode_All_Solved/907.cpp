//m0

//Thinking Process

//[A] How to Fix & Iterate? (1)

//1. fix the subarray's left endpoint, then sliding window for maintaining the min?
//1.2. still O(n^2)


//[B] How to Fix & Iterate? (2)

//1. fix the min element, and see how many subarrays can be extended with this min.
//1.2. so 2 pass for calculating last & next smaller by monotonic stack.
//1.3. then the 3rd pass calculates the results.


//[C] Duplicate Mins?
//1. what about duplicate minimums in a subarray?
//2. think about a W shape subarray, with 2 minimum elemtns.
//3. we only use the leftmost min element as the min of the subarray.
//4. how to do that?
//5. the leftward extension from the min element stops at "<=", instead of the strictly increasing "<".

//6.1. modify one of the last/next smaller --> 
//6.2. last smaller is the strictly increasing monotonic stack.
//6.3. next smaller is the non-decreasing monotonic stack.

//O(n)

#define mod ((long long)1e9 + 7LL)
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
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        //indices
        vector<int> last_smaller_strict(n, (-1));
        stack<int> monosta_strict;
        for(int i=0;i<n;i++){
            while(
                monosta_strict.size() &&
                !( arr[ monosta_strict.top() ] < arr[i] )
            ){
                monosta_strict.pop();
            }

            if(monosta_strict.size())
                last_smaller_strict[i] = monosta_strict.top();
            
            monosta_strict.push(i);
        }


        vector<int> next_smaller_nonstrict(n, n);
        stack<int> monosta_nonstrict;
        for(int i=n-1;i>=0;i--){
            while(
                monosta_nonstrict.size() &&
                !( arr[ monosta_nonstrict.top() ] <= arr[i] )
            ){
                monosta_nonstrict.pop();
            }

            if(monosta_nonstrict.size())
                next_smaller_nonstrict[i] = monosta_nonstrict.top();
            
            monosta_nonstrict.push(i);
        }


        int ans = 0;
        for(int i=0;i<n;i++){
            int l = last_smaller_strict[i];
            int r = next_smaller_nonstrict[i];

            //int overflow:
            //sub = 1e4 * 1e4 = 1e8
            //then sub = 1e8 * 1e4 = 1e12
            /*
            int sub = (
                (i-l) * (r-i)
            )%mod;

            sub = (
                sub * arr[i]
            )%mod;
            */

            long long sub = (
                (i-l) * (r-i)
            )%mod;

            sub = (
                sub * arr[i]
            )%mod;

            ans = (
                ans + sub
            )%mod;
        }

        return ans;
    }
};
