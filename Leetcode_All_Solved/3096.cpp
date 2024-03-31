class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        
        int bob = 0;
        for(int x: possible){
            if(x==1) bob++;
            else bob--;
        }
        
        int dan = 0;
        //bob at least 1 level
        for(int i=0;i+1<n;i++){
            const int x = possible[i];
            //drop for bob
            if(x==1) bob--;
            else bob++;
            
            //add for dan
            if(x==1) dan++;
            else dan--;
            
            if(dan > bob){
                return i+1;
            }
        }
        
        return (-1);
    }
};
