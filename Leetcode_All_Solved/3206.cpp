class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int a = colors[i];
            int b = colors[(i+1)%n];
            int c = colors[(i+2)%n];

            ans += a==c && a!=b;
        }
        return ans;
    }
};
