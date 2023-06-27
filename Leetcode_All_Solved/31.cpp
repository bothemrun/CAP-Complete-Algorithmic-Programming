//NOTE: best explanation from editorial's picture of of a[i-1], a[i], a[j] !
//https://leetcode.com/media/original_images/31_nums_graph.png

//read editorial's solution.

#include<assert.h>
#include<algorithm>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        //NOTE: 1. from the back, going up the hill, find the first downturn.
        //NOTE: strict downturn
        int i = n-1;
        while(i-1>=0 && !( nums[i-1] < nums[i] ) ) i--;
        int downturn = i-1;


        //NOTE: 2. case: all reversed
        if(downturn < 0){
            reverse(nums.begin(), nums.end());
            return;
        }


        //NOTE: 3. from the back, find first that > the downturn point [i-1]
        //NOTE: can also go from [i] and forwards.
        //NOTE: strict < , so next permutation is larger
        int j = n-1;
        while( !( nums[downturn] < nums[j] ) ) j--;
        int next_front = j;
        assert(downturn < next_front);//must exist by nums[i]
        

        swap(nums[downturn], nums[next_front]);


        //NOTE: 4. make the part after the new "next_front" (or the old "downturn") go from descending to ascending (non-strictly)
        assert(downturn + 1 < n);
        reverse(nums.begin() + downturn + 1, nums.end());
    }
};
