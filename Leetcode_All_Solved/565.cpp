#include<algorithm>
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        //NOTE: their in degree == out degree == 1
        //NOTE: so they form several simple circles.
        vector<bool> visited(n, false);
        int max_path = 0;
        for(int i=0;i<n;i++)if(visited[i] == false){
            int path = 0;
            int k = i;
            while(visited[k] == false){
                visited[k] = true;
                k = nums[k];
                path++;
            }
            max_path = max(max_path, path);
        }
        return max_path;

        //NTOE: TLE, O(n^2)
        /*int n = nums.size();
        int max_path = 0;
        for(int k=0;k<n;k++){
            unordered_set<int> s;
            int path = 0;
            int i = k;
            while(s.count(nums[i]) == 0){
                path++;
                s.insert(nums[i]);
                i = nums[i];
            }

            max_path = max(max_path, path);
        }
        return max_path;
        */
    }
};
