#include<algorithm>
#include<unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        for(const int& num: nums) uset.insert(num);

        int max_conse = 0;
        for(unordered_set<int>::iterator it=uset.begin();it != uset.end();it++)if(uset.count(*it - 1) == 0){
            int high = *it;
            while(uset.count(high+1) != 0) high++;

            max_conse = max(max_conse, high - (*it - 1) );
        }

        return max_conse;
    }
};



/*
#define offset ( (int)(1e9) )
#include<algorithm>
#include<unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<bool> vector_set(2*offset + 1, false);
        unordered_set<int> uset;
        for(const int& num: nums){
            vector_set[offset + num] = true;
            uset.insert(offset + num);
        }
        
        int max_conse = 0;
        for(unordered_set<int>::iterator it=uset.begin();it != uset.end();it++)if(vector_set[ *it ] == true){
            vector_set[*it] = false;
            
            int low = *it;
            int high = *it;
            
            while(low-1 >= 0 && vector_set[low-1] == true){
                vector_set[--low] = false;
            }
            
            while(high+1<=2*offset && vector_set[high+1] == true){
                vector_set[++high] = false;
            }

            max_conse = max(max_conse, high - (low-1) );
        }

        return max_conse;
    }
};
*/

/*#include<unordered_set>
#include<algorithm>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(const int& num: nums)
            s.insert(num);
        
        int max_conse = 0;
        //for(const int& num: nums){
        for(unordered_set<int>::iterator it = s.begin();it!=s.end();it++){
            int conse = 1;
            int x = *it + 1;
            while(s.count(x) != 0){
                conse++;
                x++;
            }
            max_conse = max(max_conse, conse);
        }
        return max_conse;
    }
};
*/
