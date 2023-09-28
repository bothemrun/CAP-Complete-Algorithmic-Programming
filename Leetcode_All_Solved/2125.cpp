#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        int n = bank.back().size();

        int beam = 0;
        const int no_device = (-1);
        int last_device = no_device;

        for(int i=0;i<m;i++){
            int device = 0;
            for(int j=0;j<n;j++)if(bank[i][j] == '1') device++;

            if(device == 0) continue;

            if(last_device != no_device)
                beam += last_device * device;
            
            last_device = device;
        }

        return beam;
    }
};
