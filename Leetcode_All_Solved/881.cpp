#include<algorithm>
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int boat = 0;
        int low = 0, high = n-1;
        while(low <= high){
            boat++;

            if(people[high] + people[low] <= limit){
                high--;
                low++;
            }else{
                high--;
            }
        }
        return boat;
    }
};
