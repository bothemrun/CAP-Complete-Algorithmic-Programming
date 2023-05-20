#include<algorithm>
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        //in-place
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                swap(image[i][j], image[i][n-1 - j] );
                image[i][j] = !image[i][j];
                image[i][n-1 - j] = !image[i][n-1 - j];
            }
            
            if(n%2 == 1) image[i][n/2] = !image[i][n/2];
        }

        return image;
    }
};
