#include<algorithm>
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ans = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        return letters[ (ans==letters.size())? 0:ans ];
    }
};
