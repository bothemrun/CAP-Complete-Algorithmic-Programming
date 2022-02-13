//poj2083
#include<iostream>
#include<string.h>
#include<math.h>
#define max_n 1000 //10000
char ans[max_n][max_n];
using namespace std;

inline int block_size(int n){
	return (int)(pow(3, n-1) + 0.5);
}

void fractal(char ans[][max_n], int n, int start_row, int start_col){
	if(n == 1){
		ans[start_row][start_col] = 'X';
		return;
	}

	int s = block_size(n-1);
	fractal(ans, n-1, start_row, start_col);
	fractal(ans, n-1, start_row+s, start_col+s);
	fractal(ans, n-1, start_row+s*2, start_col);
	fractal(ans, n-1, start_row, start_col+s*2);
	fractal(ans, n-1, start_row+s*2, start_col+s*2);
}

void print(char ans[][max_n], int n){
	int s = block_size(n);
	for(int i=0;i<s;i++){
		for(int j=0;j<s;j++) cout << ans[i][j];
		cout << "\n";
	}
	cout << "-\n";
}

int main(){
	int n;
	cin >> n;
	while(n != (-1)){
		memset(ans, ' ', max_n*max_n*sizeof(char));
		fractal(ans, n, 0, 0);
		print(ans, n);
		cin >> n;
	}
	return 0;
}

