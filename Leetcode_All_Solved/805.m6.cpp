//m6

//[A] turn the 4-variable float point into a 2-variable integer problem.

//1. conditions: if x/a == y/b,
//2. then x/a == (total-x)/(n-a),
//3. turn division into integer: x*(n-a) == (total-x)*a
//4. so it's a 2-variable condition for (x, a), instead of (x, a, y, b)


//[B] brute force enum?

//1. subset problem --> O(2^n)
//2. turned into a knapsack problem with O(n * n * total_sum)


//[C] pruning

//1. if x > total_sum/2, then break.
//2. assume a <= b
//3. O(max_nums*n/2 * n/2 * n) = 1e4 / 4 * 30^3 = 6.75e7  --> probably TLE.


//[E] further pruning

//1. let r := x/a
//2. then x = ar, y = br
//3. all = x+y = ar + br = (a+b)r
//4. so all/(a+b) = r = all/n
//5. so all/n = r = x/a

//6. hence, all*a = n*x
//7. x = (all*a)/n is an integer.

class Solution {
public:
    int n;
    int total_sum = 0;

    const short notyet = (-1);
    vector<vector<vector<short>>> memo;

    bool enum_knapsack_2int(const vector<int>& nums, int i, int cnt, int sum){

        if(sum<0) return false;
        if(cnt<0) return false;

        if(i==n) return cnt==0 && sum==0;

        if(memo[i][cnt][sum] != notyet) return memo[i][cnt][sum];

        //choose or skip
        return memo[i][cnt][sum] = 
            enum_knapsack_2int(nums, i+1, cnt, sum) ||
            enum_knapsack_2int(nums, i+1, cnt-1, sum-nums[i] );
    }

    bool splitArraySameAverage(vector<int>& nums) {
        this->n = nums.size();
        for(const int& x: nums) total_sum += x;

        memo.resize(n, vector<vector<short>>(n/2+1, vector<short>(total_sum/2+1, notyet) ) );

        //pruning for cnt=n/2
        //no int overflow
        for(int cnt=1;cnt<=n/2;cnt++)if( (total_sum * cnt)%n == 0){
            //total_sum*cnt = n*sum
            //sum = (total_sum*cnt) / n
            int sum = (total_sum * cnt) / n;

            //pruning
            if(sum > total_sum/2) continue;

            if( enum_knapsack_2int(nums, 0, cnt, sum) == true )
                return true;
        }

        return false;
    }
};
