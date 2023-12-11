#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();

        int portion = n/4 + 1;
        //to index
        portion -= 1;

        int size = n - portion;
        //for(int i=0;i+portion<n;i++){
        for(int i=0;i<size;i++){
            if(arr[i] == arr[i+portion] )
                return arr[i];
        }
        assert(false);
        return (-1);
    }
};
