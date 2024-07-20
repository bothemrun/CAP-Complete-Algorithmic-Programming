//m1

//[A] from m0, without hash maps.

//1. just analysis to this specific problem:
//2. max jump for each i = (i+1) --> n
//3. so memo size for jump = n+1

//4. can just use a vector map to replace the hash map of pos --> i,
//4.1. but just want to demonstrate the solution by wasabistudio:
//https://leetcode.com/problems/frog-jump/solutions/193816/concise-and-fast-dp-solution-using-2d-array-instead-of-hashmap-with-text-and-video-explanation

//5. like a tree
//6. can't use a top down dp.
#define max_n 2000

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        bool memo[max_n][max_n + 1] = {0};
        memo[0][0] = true;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                //i's last jump
                const int jump = stones[i] - stones[j];
                //jump > 0, since stones ascending.

                //pruning by jump <= n
                if(!( jump<=n )) continue;

                bool ret = false;
                //wrong: jump-1 >= 0
                if(jump-1>=0 && memo[j][jump-1]==true) ret = true;
                if(memo[j][jump]==true) ret = true;
                if(jump+1<=n && memo[j][jump+1]==true) ret = true;

                memo[i][jump] = ret;
            }
        }

        //enumerate last jump
        for(int jump=0;jump<=n;jump++)if(memo[n-1][jump] == true) return true;
        return false;
    }
};
