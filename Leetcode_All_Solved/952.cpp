//NOTE: theorem: for a number's prime factorization, at most 1 factor > sqrt(num).
//proof by contradiction.

//to avoid O(n^2) double loops in nums, group nums according to its prime factors.

#include<unordered_map>
#include<algorithm>

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
        else set_join(i, div2i[div]);
    }

    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();

        make_set(n);

        for(int i=0;i<n;i++){
            int num = nums[i];
            for(int div=2;div*div<=num;div++)if(num%div == 0){
                join_div(div, i);

                //NOTE: prime factorization by du-duplicate.
                while(num%div == 0) num /= div;
            }

            //NOTE: theorem: in a num's prime factorization, at most 1 prime factor > sqrt(num)
            if(num != 1) join_div(num, i);
        }

        return *max_element(cnt.begin(), cnt.end());
    }
};
