/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */
#include<limits.h>
class Solution {
public:
    vector<int> cnt;
    vector<int> idx;
    bool got_true_idx = false;

    inline void count(bool cur, const int& i){
        cnt[cur]++;
            
        if(got_true_idx == false && cur == true){
            got_true_idx = true;
            idx[true] = i;
        }
    }

    int guessMajority(ArrayReader &reader) {
        //NOTE: strategy: define [3] as false, then comare query(0,1,2,3) with query(0,1,2,i)
        int n = reader.length();
        cnt = vector<int>({1, 0});
        idx = vector<int>({3, INT_MIN});
        
        int diff0123 = reader.query(0, 1, 2, 3);
        
        for(int i=4;i<n;i++){
            bool cur = diff0123 != reader.query(0, 1, 2, i);

            count(cur, i);    
        }

        //NOTE: edge case: 5 <= n
        int diff0124 = reader.query(0,1,2,4);
        for(int i=0;i<=2;i++){
            bool cur = diff0124 != reader.query( (i==0)? 1:0 , (i==2)? 1:2 , 3, 4);

            count(cur, i);
        }

        if(cnt[0] > cnt[1]) return idx[0];
        else if(cnt[0] < cnt[1]) return idx[1];
        return (-1);
    }
};
