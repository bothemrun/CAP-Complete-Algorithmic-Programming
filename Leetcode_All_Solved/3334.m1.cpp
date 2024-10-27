//m1
#include<numeric> //gcd() lcm()

class Solution {
public:
    int n;
    /*
    long long gcd(long long a, long long b){
        if(a < b) return gcd(b, a);
        if(b==0) return a;
        return gcd(b, a%b);
    }
    long long lcm(long long a, long long b){
        return (a / gcd(a, b)) * b;
    }*/
    inline long long fac(const vector<int>& nums, int ban){
        const long long notyet = (-1);
        long long g = notyet, l = notyet;
        for(int i=0;i<n;i++)if(i != ban){
            if(g == notyet){
                g = nums[i];
                l = nums[i];
                continue;
            }
            
            g = gcd(g, nums[i]);
            l = lcm(l, nums[i]);
        }
        return g*l;
    }
    long long maxScore(vector<int>& nums) {
        long long ans = 0;
        n = nums.size();
        if(n==1){
            return max(0, nums.front() * nums.front() );
        }
        
        for(int ban=(-1);ban<n;ban++){
            ans = max(
                ans,
                fac(nums, ban)
            );
        }
        return ans;
    }
};
