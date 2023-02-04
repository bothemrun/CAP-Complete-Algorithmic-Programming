#include<algorithm>
class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();
        
        int ener = initialEnergy;
        
        int max_exp_deficit = 0;
        int exp = initialExperience;

        for(int i=0;i<n;i++){
            ener -= energy[i];

            max_exp_deficit = max(
                max_exp_deficit,
                max(0, 1 + experience[i] - exp)
            );
            exp += experience[i];
        }

        if(ener >= 1)
            return max_exp_deficit;
        else return max_exp_deficit + 1 - ener;
    }
};
