//[A] observation:
//1. the count of elements = 2^len(operation)
//2. divide into 2 parts (by the definition, right half = left half + 1 if we do the operation)
//3. 2. implies we decompose k into its binary representation.

//[B] reverse thinking / reverse constructive:
//1. so how do we trace back to the origin for the k'th char?
//2. that is, can we make words into half (reverse construction)?
//3. to elaborate, can we trace k's bits from higher to lower bits?

//[C] left & right half with k's i'th bit is 1:
//1. (case 1): k = 2^i + (some lower bits) --> == k = the whole left half (2^i) + part of the right half.
//2. (case 2): (some lower bits) == 0 --> then k == the whole left half (2^i) + 0 (no part of the right half)

//[D] case 1: 
//1. then check operations[i], we know whether we did the changing operation from the left half to the right half.
//2. then reverse construction discards the whole left half (and k -= 2^i)
//3. --> now, it's a havled smaller k problem, finally we'll reach word.size() == 1.

//[E] case 2:
//1. so the char we want is the only char and it's at the right end of word.
//2. we just count how many operations done from i-1.

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        vector<int> dig;
        long long x = k;
        while(x != 0){
            dig.emplace_back(x%2);
            x /= 2;
        }

        int change = 0;
        for(int i=(int)dig.size()-1;i>=0;i--)if(dig[i] == 1){
            if(k == (1LL<<i)){
                for(int j=i-1;j>=0;j--)
                    change += operations[j];
                break;
            }

            change += operations[i];
            k -= (1LL<<i);
        }
        return change%26 + 'a';
    }
};
