//m0
//Thinking Process:


//[A] sort frequencies.


//[B] Reverse Thinking From Results:

//1. after all deletions, the lowest frequency is low_f.
//2. then delete freq < low_f, trim freq > k + low_f by prefix sum.


//[C] like binary search the answer


//O(26*max frequency + n) = O(26*n)
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
        const int max_f = (int)1e5;

        vector<int> cnt(alpha, 0);
        for(const char& c: word) cnt[c-'a']++;

        sort(cnt.begin(), cnt.end());

        //no overflow
        vector<int> prefix(alpha);
        prefix.front() = cnt.front();
        for(int i=1;i<alpha;i++) prefix[i] = prefix[i-1] + cnt[i];


        int min_del = (int)word.size() + 1;
        for(int f=1;f<=max_f;f++){
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
