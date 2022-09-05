#include<algorithm>
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cur_recolor = k;
        for(int i=0;i<k;i++){
            if(blocks.at(i) == 'B') cur_recolor--;
        }
        int min_recolor = cur_recolor;
        
        for(int tail=k;tail<blocks.size();tail++){
            if(blocks.at(tail) == 'W') cur_recolor++;
            int head = tail - k;
            if(blocks.at(head) == 'W') cur_recolor--;
            
            min_recolor = min(min_recolor, cur_recolor);
        }
        return min_recolor;
    }
};
