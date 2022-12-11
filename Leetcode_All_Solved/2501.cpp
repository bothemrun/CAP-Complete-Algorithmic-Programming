#include<unordered_set>
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        unordered_set<long long> s;
        for(int i=0;i<n;i++){
            s.insert((long long)nums[i]);
        }
        
        int max_streak = (-1);
        for(int i=0;i<n;i++){
            long long x = nums[i];
            int streak = 1;
            while(s.count(x*x) != 0){
                streak++;
                x = x*x;
            }
            
            if(streak >= 2) max_streak = max(max_streak, streak);
        }
        return max_streak;
    }
};
