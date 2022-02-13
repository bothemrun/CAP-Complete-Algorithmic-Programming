//uva439
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
//TODO: overflow to negative #include<limits.h>
#define KNIGHT_MOVES_MAX 1000
#define chess_size 8
using namespace std;

inline bool in_board(int x, int y){ return 0 <= x && x < chess_size && 0 <= y && y < chess_size; }

inline void make_adj(int d[chess_size][chess_size][chess_size][chess_size], int dx[], int dy[], int n_dx_dy){
	//TODO: memset(d,0,sizeof(d));
	for(int ix=0;ix<chess_size;ix++)
	for(int iy=0;iy<chess_size;iy++)
		for(int jx=0;jx<chess_size;jx++)
		for(int jy=0;jy<chess_size;jy++) d[ix][iy][jx][jy] = (ix==jx && iy==jy)? 0:KNIGHT_MOVES_MAX;
			//TODO: d[ix][iy][jx][jy] = (ix==jx && iy==jy)? 0:INT_MAX;
	//TODO: INT_MAX + INT_MAX overflow to negative

	for(int x=0;x<chess_size;x++)
	for(int y=0;y<chess_size;y++)
	for(int k=0;k<n_dx_dy;k++){
		int xx = x + dx[k];
		int yy = y + dy[k];
		if(!in_board(xx, yy)) continue;
		d[x][y][xx][yy] = 1;
	}
}

inline void floyd_warshall(int d[chess_size][chess_size][chess_size][chess_size]){
	for(int kx=0;kx<chess_size;kx++)
	for(int ky=0;ky<chess_size;ky++)
		for(int ix=0;ix<chess_size;ix++)
		for(int iy=0;iy<chess_size;iy++)
			for(int jx=0;jx<chess_size;jx++)
			for(int jy=0;jy<chess_size;jy++)
				d[ix][iy][jx][jy] = min(d[ix][iy][jx][jy], d[ix][iy][kx][ky] + d[kx][ky][jx][jy]);
}

int main(){
	int d[chess_size][chess_size][chess_size][chess_size];
	int dx[] = {2,2,  -2,-2, 1,-1, 1, -1};
	int dy[] = {1,-1, 1, -1, 2,2,  -2,-2};
	//floyd warshall
	make_adj(d, dx, dy, sizeof(dx)/sizeof(int));
	floyd_warshall(d);

	string line;
	while(getline(cin, line) && line.size() != 0){
		int x1 = line[0] - 'a';
		int y1 = line[1] - '1';
		int x2 = line[3] - 'a';
		int y2 = line[4] - '1';
		cout << "To get from " << line.substr(0, 2) << " to " << line.substr(3, 2) << " takes " << d[x1][y1][x2][y2] << " knight moves.\n";
	}
	return 0;
}

