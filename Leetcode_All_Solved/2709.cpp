//NOTE: Theorem: at most 1 prime factor > sqrt(num)
//proof: by contradiction. 
//if exists prime factors p q > sqrt(num),
//then p * q  > num.  contradiction.



//too slow if we check all gcd 1 by 1.
//so like the prime sieve, find a number's factor in sqrt(number)

//then group numbers with a specific common divisor together.

//we also prune by dividing the same divisor from num.

#include<unordered_map>

class Solution {
public:
    vector<int> dsu;
    vector<int> rank;
    vector<int> cnt;
    inline void make_set(int size){
        dsu.resize(size);
        for(int i=0;i<size;i++) dsu[i] = i;

        rank.resize(size, 1);
        cnt.resize(size, 1);
    }
    int set_find(const int& a){
        if(dsu[a] == a) return a;
        return dsu[a] = set_find(dsu[a]);
    }
    inline void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a==b) return;

        if(rank[a] < rank[b]){
            dsu[a] = b;
            cnt[b] += cnt[a];
        }else if(rank[a] > rank[b]){
            dsu[b] = a;
            cnt[a] += cnt[b];
        }else{
            dsu[a] = b;
            rank[b]++;
            cnt[b] += cnt[a];
        }
    }


    unordered_map<int,int> div2i;
    inline void join_div(const int& div, const int& i){
        if(div2i.count(div) == 0) div2i[div] = i;
        else set_join(i, div2i[div] );
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        make_set(n);

        for(int i=0;i<n;i++){

            int num = nums[i];

            for(int div=2;div*div <= num;div++)if(num % div == 0){
                join_div(div, i);

                //NOTE: pruning
                while(num % div == 0) num /= div;
            }

            //NOTE: theorem: at most 1 divisor > sqrt(num)
            if(num != 1) join_div(num, i);
        }

        return cnt[ set_find(0) ] == n;
    }
};
