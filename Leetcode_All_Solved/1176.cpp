class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n = calories.size();

        int window = 0; //no overflow
        for(int i=0;i<k-1;i++)
            window += calories[i];
        
        int ans = 0;
        for(int i=k-1;i<n;i++){
            window += calories[i];

            if(window < lower) ans--;
            else if(window > upper) ans++;

            window -= calories[ i - (k-1) ];
        }

        return ans;
    }
};
