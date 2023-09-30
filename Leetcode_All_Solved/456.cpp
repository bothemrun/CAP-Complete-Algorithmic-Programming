//m0
//monotonic stack's 132 for increasing / 312 for decreasing property.
//O(n)

// Thinking Process:

//1. for the 2 to find the 3 --> find last larger --> decreasing monotonic stack
//1.1. better understand all these by drawing 312 stack diagram.

//2. but to find the 1 for this 2?
//2.1. not the valley between this 2 and this 3.
//2.2. but find the 1 in the 3's previous valley.

//3. so just keep a map of the min of the (popped) values in the valley
//3.1. by (2.2.), if the min the the 3's previous valley < nums[i] currently processed, then good.

//4. but the problem is: can the 1 exist in further previous valleys?
//4.1. that is, further previous valleys have smaller values (called 1a) than the 3's previous vallley min (called 1b) that we are handling?

//5. prove by contradiction:
//5.1. if yes, then the further previous valley 1a, the next peak, the 3's previous valley 1b, forms 132 pattern.
//contradiction, we would already have found it and returned true.
//5.2. this is better explained by drawing a graph.

#include<stack>
#include<algorithm>
#include<limits.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();

        vector<int> valley_min(n, INT_MAX);
        stack<int> last_larger;
        for(int i=0;i<n;i++){

            while(
                last_larger.size() != 0 &&
                !( nums[ last_larger.top() ] > nums[i] )
            ){
                //NOTE: also compare the valley min of the popped element.
                valley_min[i] = min({
                    valley_min[i],
                    nums[ last_larger.top() ],
                    valley_min[ last_larger.top() ]
                });
                
                last_larger.pop();
            }

            if(
                last_larger.size() != 0 &&
                valley_min[ last_larger.top() ] < nums[i]
            ) return true;

            last_larger.push(i);
        }

        return false;
    }
};
