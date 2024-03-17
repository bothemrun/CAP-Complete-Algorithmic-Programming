//m1
//Thinking Process:


//[A] sort frequencies.


//[B] Reverse Thinking From Results:

//1. after all deletions, the lowest frequency is low_f.
//2. then delete freq < low_f, trim freq > k + low_f by prefix sum.


//[C] like binary search the answer





//[D] search range?

//1. m0 searches resultant lowest frequency = 1 ~ max_frequqncy = 1e5.

//2. the actual deletion: delete min non-0 f / decrease max f, repeatedly.
//2.a. that is, 1 of them must die.

//3. and the deleted / decreased f is forever safe that we can ignore it afterwards.
//3.a. 'cuz it's already compatible with the extremum.

//4. the process in 2. stops when only 1 remains / the un-modified are all compatible.

//5. so the resultant lowest frequency is un-modified.

//6. hence, we can just enumerate f = all 26 frequencies.




//O(26*26 + n) = O(n)
//improved from m0 O(26*max_frequency + n) = O(26*n)

//practically, for chars, simple loop is faster than priority queue.

#define range_sum(i, j) ( prefix[j] - ( (i-1>=0)? prefix[i-1]:0 ) )

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minimumDeletions(string word, int k) {
        const int alpha = 26;
        vector<int> cnt(alpha, 0);
        for(const char& c: word) cnt[c-'a']++;

        sort(cnt.begin(), cnt.end());

        //no overflow
        vector<int> prefix(alpha);
        prefix.front() = cnt.front();
        for(int i=1;i<alpha;i++) prefix[i] = prefix[i-1] + cnt[i];


        int min_del = (int)word.size() + 1;
        for(const int& f: cnt){
            int del = 0;

            //practically, for chars, simple loop is faster than priority queue.
            int low = 0;
            for(;low<alpha;low++)if( f <= cnt[low] ) break;

            if(low-1>=0){
                del += range_sum(0, low-1);
            }


            int high = alpha-1;
            for(;high>=0;high--)if( cnt[high] <= f+k ) break;

            if(high+1<alpha){
                del += range_sum(high+1, alpha-1);

                int rectangle = (f+k) * ( (alpha-1) - high );
                del -= rectangle;
            }

            min_del = min(min_del, del);
        }

        return min_del;
    }
};
