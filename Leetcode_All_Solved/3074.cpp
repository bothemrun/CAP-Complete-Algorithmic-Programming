class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end());
        int sum = 0;
        for(const int& a: apple) sum += a;

        int m = capacity.size();
        int i=m-1;
        for(;i>=0;i--){
            sum -= capacity[i];

            if(sum <= 0) break;
        }

        return m - i;
    }
};
