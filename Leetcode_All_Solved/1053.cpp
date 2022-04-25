#include<algorithm>//swap()
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        if(arr.size() == 1)return arr;
        
        int n = arr.size();
        //find 1st strict turning point
        int turn = n-1-1;
        while(turn >= 0 && !(arr[turn] > arr[turn+1]) )turn--;
        //no strict turning point
        if(turn == (-1))return arr;
        
        //among elements smaller than it and to the right, find biggest(if many same, the leftmost)
        int swap_i = n-1;
        while(arr[turn] <= arr[swap_i])swap_i--;
        while(arr[swap_i] == arr[swap_i-1])swap_i--;
        swap(arr[turn], arr[swap_i]);
        return arr;
    }
};
