//O(n)
class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();

        int step = n;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += plants[i];

            if(i+1<n && plants[i+1] + sum > capacity){
                //refill
                step += 2 * ( i - (-1) );

                sum = 0;
            }
        }

        return step;
    }
};
