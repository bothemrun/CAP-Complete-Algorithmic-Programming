#include<algorithm>
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_window = 0;
        int flip = k;
        int cur_win_size = 0;
        for(int high=0;high<(int)nums.size();high++){
            if(nums[high] == 1){
                max_window = max(max_window, ++cur_win_size);
            }else if(flip > 0){
                flip--;
                max_window = max(max_window, ++cur_win_size);
            }else{
                while(nums.at( high-cur_win_size ) == 1)cur_win_size--;
                //if(cur_win_size==0) directly out
            }
        }
        return max_window;
    }
};
