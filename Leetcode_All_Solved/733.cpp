#include<string.h>
#define max_mn 50
class Solution {
private:
    void dfs(vector<vector<int>>& image, bool visited[][max_mn], int sr, int sc, const int& sColor, const int& newColor, const int& m, const int& n){
        if(!( 0<=sr && sr<m && 0<=sc && sc<n && image[sr][sc] == sColor && visited[sr][sc] == false )) return;
        //visit
        visited[sr][sc] = true;
        image[sr][sc] = newColor;
        //dfs
        dfs(image,visited,sr+1,sc,sColor,newColor,m,n);
        dfs(image,visited,sr-1,sc,sColor,newColor,m,n);
        dfs(image,visited,sr,sc+1,sColor,newColor,m,n);
        dfs(image,visited,sr,sc-1,sColor,newColor,m,n);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        int sColor = image[sr][sc];
        bool visited[max_mn][max_mn];
        memset(visited,0,sizeof(visited));
        dfs(image,visited,sr,sc,sColor,newColor,m,n);
        return image;
    }
};
