class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i=0;
        while(i<n-2){
            if(bits[i] == 0) i++;
            else i += 2;
        }
        
        if(i==n-1) return true;//bits.back() == 0
        assert(i==n-2);
        return (bits[i]==1)? false:true;
    }
};
