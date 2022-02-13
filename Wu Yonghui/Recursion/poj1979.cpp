//poj1979
#include<iostream>
#include<string.h> //memset
using namespace std;
#define MAX_WH 21

void search(const int& W, const int& H, int row, int col, int tile[][MAX_WH], int& n_black_tile){
	if(col < 0 || W <= col || row < 0 || H <= row) return;
	else if(tile[row][col] != 1) return; 

	n_black_tile++;
	tile[row][col] = 0;
	search(W, H, row+1, col, tile, n_black_tile);
	search(W, H, row-1, col, tile, n_black_tile);
	search(W, H, row, col+1, tile, n_black_tile);
	search(W, H, row, col-1, tile, n_black_tile);
}

int main(){
	int tile[MAX_WH][MAX_WH];
	int W, H;
	cin >> W >> H;
	while(W && H){
		int row, col;
		char ch;
		memset(tile, 0, sizeof(tile));
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				cin >> ch;
				if(ch == '@'){
					row = i;
					col = j;
					tile[i][j] = 1;
				}else if(ch == '.')
					tile[i][j] = 1;
			}
		}

		int n_black_tile = 0;
		search(W, H, row, col, tile, n_black_tile);
		cout << n_black_tile << "\n";

		cin >> W >> H;
	}
	return 0;
}

