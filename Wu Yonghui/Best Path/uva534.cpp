//uva534
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<limits.h>
#include<algorithm>
#define max_n 202
using namespace std;

inline void floyd(int conn[][max_n], int n){
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) conn[i][j] |= conn[i][k] & conn[k][j];
}

inline void binary(double l, double r, double d[][max_n], int n){
	if(r - l <= 1e-5){
		printf("Frog Distance = %.3f\n", l);
		return;
	}

	double mid = l + (r-l)/2;
	int conn[max_n][max_n];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		conn[i][j] = (d[i][j] <= mid)? 1:0;

	floyd(conn, n);

	if(conn[1][2]) binary(l, mid, d, n);
	else binary(mid, r, d, n);
}

int main(){
	int n_case = 0;
	int n;
	cin >> n;
	while(n != 0){
		int x[n+1], y[n+1];
		for(int i=1;i<=n;i++) cin >> x[i] >> y[i];
		
		double maxd = INT_MIN;
		double mind = INT_MAX;
		double d[max_n][max_n]; 
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){ 
			d[i][j] = sqrt( pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2) );
			maxd = max(maxd, d[i][j]);
			mind = min(mind, d[i][j]);
		}

		cout << "Scenario #" << ++n_case << "\n";
		binary(mind, maxd, d, n);
		cout << "\n";

		cin >> n;
	}
	return 0;
}

