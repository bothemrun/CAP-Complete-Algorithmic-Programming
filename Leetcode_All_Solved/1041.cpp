//Thinking Process

//[A] Assumption
//1. after 1 loop of instructions, we're at (x1, y1) == the delta vector 
//2. with direction = dir1
//3. see what happens after n loops.

//[B] If dir1 == north:
//1. we're at (n * x1, n * y1), not cyclic

//[C] If dir1 == south:
//1. we're at (x1 - x1, y1 - y1) for n%2 == 0
//2. that is, the delta vector is turned 180 degrees after each loop.

//[D] If dir1 == east / west
//1. WLOG, assume east.
//2. we're at (0, 0) for n%4 == 0
//3. that is, the delta vector is turned 90 degrees after each loop.

//[E] Conclusion
//1. go thru the instructions 4 times.
//2. check if the location is the same.

class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        int dir = 0;
        int x_start = 0, y_start = 0;
        int x=x_start, y=y_start;
        for(int t=0;t<4;t++){
            for(const char& instr: instructions){
                if(instr == 'G'){
                    x += dx[dir];
                    y += dy[dir];
                }else if(instr == 'R'){
                    dir = (dir+1)%4;
                }else{
                    dir = (dir-1 + 4)%4;
                }
            }
        }

        return x==x_start && y==y_start;
    }
};
