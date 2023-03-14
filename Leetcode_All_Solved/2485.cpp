class Solution {
public:
    int pivotInteger(int n) {
        int sum = 0;
        for(int i=1;i<=n;i++) sum += i;
        int prefix = 0;
        for(int i=1;i<=n;i++){
            if(prefix + i == sum - prefix) return i;

            prefix += i;
        }
        return (-1);
    }
};
