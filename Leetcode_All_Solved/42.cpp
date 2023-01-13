//NOTE: for each "pool" of water, we sum each water rectangle following horizontal layer by layer.
#define test 0 // 1 0
#include<stack>
#include<algorithm>
class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;

        stack<int> mono_sta;

        for(int i=0;i<height.size();i++){

            while(mono_sta.size() > 0 && height[ mono_sta.top() ] <= height[i]){
                
                int floor = height[ mono_sta.top() ];

                mono_sta.pop();
                
                if(mono_sta.size() == 0)break;

                int wall = min(
                    height[i],
                    height[ mono_sta.top() ]
                );

                int width = (i-1) - mono_sta.top();

                
                water += (wall - floor) * width;
                #if test == 1
                printf("i %d wall %d width %d floor %d water %d\n", i, wall, width, floor, water);
                #endif
            }

            mono_sta.push(i);
        }//for i

        return water;
    }
};
