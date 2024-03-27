//Greedy Proof:

//1. for any increase operations, it's better to apply to the max element.

//2. for any duplicate operations, it's better to apply to the max element.

//3. so it's better to use only 1 element.
//4. then it's worse to apply duplicate before any times of increase.

//5. so we can enumerate all combinations of (increase, duplicate) operations.

//O(k) = 1e5

class Solution {
public:
    inline int ceil(const int& a, const int& b){
        if(a%b == 0) return a/b;
        else return a/b+1;
    }

    int minOperations(int k) {
        int min_op = k+2;

        for(int inc=0;inc<=k-1;inc++){
            int max_ele = 1 + inc;

            int dup = ceil(k, max_ele) - 1;
            assert(dup >= 0);

            min_op = min(min_op, inc + dup);
        }

        return min_op;
    }
};
