//m1
//Thinking Process:
//1. the critical part is to prove choice choice / local optimal leads to global optimal.
//2. most solutions didn't prove this.



//[A] divide:

//1. costs to the original non-? chars
//2. mutual costs of the replaced ? chars


//[B] first think in brute force:

//1. --> actullay calculate the extra costs to the original non-? chars.
//2. if I replace ? at s[i] with char := ch,
//3. the extra cost = prefix_sum[i] of count[ch] + suffix_sum[i] of count[ch]
//4. so the position i / the order doesn't matter for this extra cost to the original non-? chars.


//[C] greedy choice: local optimal:

//1. for each ?, fill it with the char with the smallest "current" frequency.
//2. then update the frequencies.


//[D] greedy proof: local optimal to global optimal --> reverse thinking from results / reversed time:

//1. suppose we have a filled result R1.
//2. change a fillled char to the char with the smallest frequency.
//2.a. this result R2 is better than R1.
//3. do this repeatedly, in reversed time / reversed thinking from results.
//4. so this reversed thinking from results / reversed time is the reversal of [C] greedy choices.



//[E] lexicographically smallest:

//1. by [D], we know the chars to replace, but the order in [D] is not done.
//2. by [B], the order doesn't matter.
//3. so sort [D].
//4. optimization: don't sort all replaced '?' in O(nlogn), just count chars of replaced '?'

//O(n + n*26 + n)

#define alphabet 26
/*
#define tic tuple<int, char>
#include<tuple>
#include<queue>
*/
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string minimizeStringValue(string s) {
        int qm_n = 0;

        vector<int> cnt(alphabet, 0);
        for(const char& c: s){
            if(c == '?'){
                qm_n++;
                continue;
            }

            cnt[c-'a']++;
        }


        /*
        auto cmp = [](const tic& a, const tic& b){
            const auto& [acnt, achar] = a;
            const auto& [bcnt, bchar] = b;
            if(acnt != bcnt) return acnt > bcnt;//min heap for count
            return achar > bchar;//min heap lexicographically
        };
        priority_queue< tic, vector<tic>, decltype(cmp) > minheap(cmp);

        for(char c='a';c<='z';c++){
            minheap.push( tic(cnt[c-'a'], c) );
        }
        */


        vector<int> qm_cnt(alphabet, 0);

        for(int i=0;i<qm_n;i++){
            //use simple loop instead of priority queue.
            //practically, it's faster.
            int min_cnt = INT_MAX;
            char min_cha = '#';
            for(char cha='a';cha<='z';cha++)if( cnt[cha-'a'] < min_cnt ){
                if(min_cha != '#') cnt[ min_cha-'a' ]--;

                min_cnt = cnt[cha-'a']++;
                min_cha = cha;
            }

            qm_cnt[ min_cha-'a' ]++;

            /*
            const auto [count, cha] = minheap.top();
            minheap.pop();

            qm_cnt[ cha-'a' ]++;

            minheap.push( tic( count+1, cha ) );
            */
        }


        //optim: not sorting O(nlogn), just count chars of replaced '?'
        int qm_i = 0;
        for(char& c: s)if(c == '?'){
            while( qm_cnt[qm_i] == 0 ){
                qm_i++;
            }

            c = 'a' + qm_i;
            qm_cnt[qm_i]--;
        }

        return s;
    }
};
