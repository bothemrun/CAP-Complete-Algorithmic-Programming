#include<assert.h>
#include<queue>
class cmp_class{
public:
    bool operator()(const int& a, const int& b){
        return a < b;//max heap, sink down
    }
};
class Solution {
public:
    int n, b;
    priority_queue<int, vector<int>, cmp_class> max_heap;
    
    inline void use_all_bricks(const vector<int>& heights, int& bricks){

        while(b <= n-2 && 
            ( heights[b+1] - heights[b] <= 0 || 
            bricks >= heights[b+1] - heights[b] ) 
        ){
            if(heights[b+1] > heights[b]){
                bricks -= heights[b+1] - heights[b];
                max_heap.push( heights[b+1] - heights[b] );
            }
            b++;
        }
    }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        n = heights.size();
        b = 0;
        
        for(int i=0;i<ladders;i++){
            use_all_bricks(heights, bricks);


            if(b == n-1) break;

            assert(heights[b+1] > heights[b]);
            if(max_heap.size() == 0){
                b++;
                continue;
            }

            /*bricks += max_heap.top();
            max_heap.pop();*/

            max_heap.push( heights[b+1] - heights[b] );
            //NOTE: include the next diff being the max diff.
            bricks += max_heap.top() - ( heights[b+1] - heights[b] );
            b++;
            max_heap.pop();
        }

        //NOTE: use the remaining
        use_all_bricks(heights, bricks);

        return b;
    }
};
