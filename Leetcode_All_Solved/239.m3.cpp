//m3
//monotonic queue implemented by deque
//O(n)
#include<deque>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        deque<int> deck;//of indices
        for(int i=0;i<n;i++){
            while(deck.size() && !( nums[ deck.back() ] > nums[i] )){
                deck.pop_back();
            }

            deck.push_back(i);

            //update, drop, maintain the window
            //size > 0, since deck.push_back(i)
            while(deck.front() <= i-k){
                deck.pop_front();
            }

            //size > 0, since deck.push_back(i)
            if(i-k + 1>=0){
                ans.push_back(nums[ deck.front() ]);
            }
        }
        return ans;
    }
};
