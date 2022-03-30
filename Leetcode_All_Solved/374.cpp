/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
private:
    int binary_search(int low, int high){
        int mid = low + (high-low)/2;
        if(guess(mid) == 0)return mid;//applies for size 1
        if(low == high)return (-2);
        
        if(guess(mid) == 1)return binary_search(mid+1, high);
        else return binary_search(low, mid);
    }
public:
    int guessNumber(int n) {
        return binary_search(1, n);
    }
};
