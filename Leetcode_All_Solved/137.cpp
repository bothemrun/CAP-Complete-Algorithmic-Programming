#include <unordered_map>
#include <utility> // pair
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 1. build a hash map : value -> times
        unordered_map<int, int> num_to_times;
        hash_num_to_times(nums, num_to_times);
        
        // 2. traverse over hash map, looking for item with times == 1
        for(unordered_map<int, int>::iterator it = num_to_times.begin();it != num_to_times.end();it++){
            if(it->second == 1){
                // 1 times
                return it->first;
            }
        }//for it
        
        // won't be here
        return 0; // no answer
    }//singleNumber
    
    void hash_num_to_times(vector<int>& nums, unordered_map<int, int>& num_to_times){
        for(vector<int>::iterator it = nums.begin();it != nums.end();it++){
            unordered_map<int, int>::iterator found = num_to_times.find(*it);
            if(found == num_to_times.end()){
                // create new item
                pair<int, int> num_to_1_time (*it, 1);
                num_to_times.insert(num_to_1_time);
            } else{
                // add times to existing item
                (found->second)++;
            }//else
        }//for it
    }
};
