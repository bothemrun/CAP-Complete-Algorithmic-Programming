#include<algorithm>
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int window_size = 0;
        for(int& d: data)if(d == 1)
            window_size++;
        
        int window0 = 0;
        for(int i=0;i<window_size;i++)if(data[i] == 0)
            window0++;
        
        int min_swap = window_size;
        for(int i=window_size-1;i<data.size();i++){
            min_swap = min(min_swap, window0);
            
            //update
            int i_add = i + 1;
            if(!(i_add < data.size()))break;
            //delete
            int i_del = i - (window_size-1);
            if(data[i_del] == 0)
                window0--;
            //add
            if(data[i_add] == 0)
                window0++;
        }
        return min_swap;
    }
};
