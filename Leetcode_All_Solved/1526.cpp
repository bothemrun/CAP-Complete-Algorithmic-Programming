//m0
//Thinking Process:
//idea: build bricks upwards

//[Part 1: brute force]
//(1) the best & greedy way is to stack bricks upwards 1 layer by layer.
//(2) for a layer, there are groups of consecutive places for bricks.
//(3) each group takes 1 operation.
//(4) now we have a brute force algorithm in O(max layer * n)

//[Part 2: wall height]
//(5) for a group at any layer, it must have left & right walls.
//(6) so answer = sum of left & right wall heights / 2
//(7) or answer = sum of left or right wall heights.

//[Part 3: O(n) algorithm]
//(8) so answer = sum of left & right wall heights / 2 = sum of abs( difference ) of all adjacent elements / 2 
//(by (6))

#include<stdlib.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        //diff of left wall of front with the ground
        //diff of right wall of back with the ground
        long long wall_height_sum = target.front() + target.back();

        for(int i=0;i+1<n;i++)
            wall_height_sum += abs( target[i] - target[i+1] );
        
        return wall_height_sum / 2;
    }
};
