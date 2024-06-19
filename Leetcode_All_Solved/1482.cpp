//optimization --> dp, greedy, binary search the answer.

//if we can do it in x days, then also for days y>=x.
//binary search the answer.
//O(n * log(max_day)) = O(nlog10^0) = O(30*n)

#define max_day ((int)1e9)
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n, m, k;
    inline bool good(const vector<int>& bloomDay, const int day_bound){
        int bouquet = 0;

        int i=0;
        while(i<n){
            if(bloomDay[i] > day_bound){
                i++;
                continue;
            }

            //[i, j] consecutive bloomed flowers
            int j=i;
            while(j+1<n && bloomDay[j+1] <= day_bound){
                j++;
            }

            int len = j - (i-1);
            bouquet += len / k;

            if(bouquet >= m) return true;

            //update
            i = j+1;
        }

        return false;
    }

    int binary_ans(const vector<int>& bloomDay, int low, int high){
        int mid = low + (high-low)/2;

        bool mid_res = good(bloomDay, mid);
        if(mid_res==true && good(bloomDay, mid-1)==false)
            return mid;
        
        if(mid_res==true)
            return binary_ans(bloomDay, low, mid);
        else
            return binary_ans(bloomDay, mid+1, high);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        this->n = bloomDay.size();
        this->m = m;
        this->k = k;

        //if(n < m*k) return (-1); overflow
        if((long long)n < (long long)m*(long long)k) return (-1);

        return binary_ans(bloomDay, 1, max_day);
    }
};
