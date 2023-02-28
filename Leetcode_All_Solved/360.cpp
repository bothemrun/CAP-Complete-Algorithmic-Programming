#include<assert.h>
#include<algorithm>
#include<math.h> //ceil()
class Solution {
public:
    int a, b, c;
    inline int quadratic(const int& x){
        return a*x*x + b*x + c;
    }
    inline int quadratic_vertex(double a, double b, double c){
        assert(a != 0);
        return (int)ceil( (-b)/(2*a) );
    }
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
        int n = nums.size();
        
        //NOTE: edge case
        if(a == 0){
            /*for(int& x: nums) x = quadratic(x);
            return nums;*/
            //NOTE: edge case
            vector<int> quad(n);
            for(int i=0;i<n;i++)
                quad[i] = quadratic(nums[ (
                    (b >= 0)? i:(n-1 - i)
                ) ]);
            return quad;
        }
        int vertex = quadratic_vertex((double)a, (double)b, (double)c);

        //NOTE: optim by binary search
        int j = lower_bound(nums.begin(), nums.end(), vertex) - nums.begin();
        int i = j - 1;

        int q_i, q_j;
        if(0 <= i) q_i = quadratic(nums[i]);
        if(j < n) q_j = quadratic(nums[j]);

        vector<int> quad(n);
        int k = 0, delta = 1;
        if(a < 0){
            k = n-1;
            delta = (-1);
        }

        //merge 2 sorted list
        while(0 <= i && j < n){
            //NOTE:
            if(delta*q_i < delta*q_j){
                quad[k] = q_i;
                if(--i >= 0) q_i = quadratic(nums[i]);
            }else{
                quad[k] = q_j;
                if(++j < n) q_j = quadratic(nums[j]);
            }

            k += delta;
        }

        while(0 <= i){
            quad[k] = q_i;
            if(--i >= 0) q_i = quadratic(nums[i]);
            k += delta;
        }
        while(j < n){
            quad[k] = q_j;
            if(++j < n) q_j = quadratic(nums[j]);
            k += delta;
        }

        return quad;
    }
};
