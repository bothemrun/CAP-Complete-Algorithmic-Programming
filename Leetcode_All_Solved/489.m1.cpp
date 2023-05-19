/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
//m1
//vector map instead of 2d hash map.

//NOTE: watch out the coordination delta different for each 4 orientations
#include<assert.h>
#define max_n 201
#define offset 201
#define max_size (max_n + offset + 2)
class Solution {
public:
    bool vecmap[max_size][max_size] = {0};
    //NOTE: clockwise
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0,  1, 0, -1};

    inline bool visited(const int& i, const int& j){
        return vecmap[i+offset][j+offset];
    }
    inline void visit(const int& i, const int& j){
        vecmap[i+offset][j+offset] = true;
    }
    void back_next_oriented(Robot& robot, int i, int j, int dir){
        if(robot.move()){
            clean_room_same_oriented(robot, i, j, dir);
            robot.turnRight();
            robot.turnRight();
            assert(robot.move());
            robot.turnLeft();
        }else robot.turnRight();
    }
    void clean_room_same_oriented(Robot& robot, int i, int j, int dir){
        if(visited(i, j)) return;
        visit(i, j);

        robot.clean();//this

        for(int k=0;k<4;k++){//NOTE: clockwise
            //NOTE: watch out the coordination delta different for each 4 orientations
            int new_dir = (dir + k)%4;
            back_next_oriented(robot, i + di[ new_dir ], j + dj[ new_dir ], new_dir);
        }

        //NOTE: maintains the same orientation
    }
    void cleanRoom(Robot& robot) {
        clean_room_same_oriented(robot, 0, 0, 0);
    }
};
