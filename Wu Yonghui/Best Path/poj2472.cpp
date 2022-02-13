//poj2472
#include<iostream>
#include<stdio.h>
#define max_n 100
using namespace std;

inline void floyd_warshall(double d[][max_n+1], int n){
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) d[i][j] = max(d[i][j], d[i][k]*d[k][j]);
}

int main(){
	while(1){
		int n, m;
		cin >> n >> m;
		if(n == 0) break;

		//not dag, longest path, so floyd warshall in O(n^3)
		//adj matrix
		double d[max_n+1][max_n+1];
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) d[i][j] = (i == j)? 1.0:0.0;

		for(int i=0;i<m;i++){
			int a, b;
			double p;
			cin >> a >> b >> p;
			d[a][b] = p/100.0;
			d[b][a] = p/100.0;
		}

		//floyd warshall
		floyd_warshall(d, n);
		printf("%.6f percent\n", d[1][n]*100);
	}

	return 0;
}

