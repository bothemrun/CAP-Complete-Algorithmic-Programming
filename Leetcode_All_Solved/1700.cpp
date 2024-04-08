//m0
//O(n)

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();

        vector<int> want(2, 0);
        for(const int& x: students) want[x]++;

        for(int i=0;i<n;i++){
            if( want[ sandwiches[i] ]-- == 0) return n - i;
        }
        return 0;
    }
};
