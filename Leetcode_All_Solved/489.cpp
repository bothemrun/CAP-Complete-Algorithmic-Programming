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
//m0
//2d hash map
//NOTE: watch out the coordination delta different for each 4 orientations
#include<unordered_map>
#include<unordered_set>
#include<assert.h>
class Solution {
public:
    unordered_map<int, unordered_set<int>> umap2d;

    //NOTE: watch out the coordination delta different for each 4 orientations
    //clockwise
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0,  1, 0, -1};

    inline bool visited(int i, int j){
        if(umap2d.count(i) == 0) return false;
        return umap2d[i].count(j) != 0;
    }
    inline void visit(int i, int j){
        umap2d[i].insert(j);
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

        //NOTE: watch out the coordination delta different for each 4 orientations
        //NOTE: all relative to current orientation
        for(int k=0;k<4;k++){
            //clockwise
            int new_dir = (dir + k)%4;
            back_next_oriented(robot, i+di[ new_dir ], j+dj[ new_dir ], new_dir);
        }

        //NOTE: maintains old orientation
    }
    void cleanRoom(Robot& robot) {
        clean_room_same_oriented(robot, 0, 0, 0);
    }
};
