//poj1125
#include<iostream>
#include<algorithm>
#define MAX_TIME (10*100*10)
#define MAX_STOCKBROKER 100
using namespace std;

inline void floyd_warshall(int d[][MAX_STOCKBROKER+1], int N){
	for(int k=1;k<=N;k++)
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

inline void min_max(int d[][MAX_STOCKBROKER+1], int N){
	int min_time = MAX_TIME;
	int min_time_start = -1;
	for(int i=1;i<=N;i++){
		//find max
		int max_time = -1;
		for(int j=1;j<=N;j++)
			if(i != j && d[i][j] > max_time) max_time = d[i][j];

		//update min
		if(max_time < min_time){
			min_time = max_time;
			min_time_start = i;
		}
	}

	if(min_time == MAX_TIME) cout << "disjoint\n";
	else cout << min_time_start << " " << min_time << "\n";
}

int main(){
	int N;
	cin >> N;
	while(N != 0){
		//adj matrix
		int d[MAX_STOCKBROKER+1][MAX_STOCKBROKER+1];
		for(int i=0;i<N+1;i++)
		for(int j=0;j<N+1;j++) d[i][j] = (i == j)? 0:MAX_TIME;
		//TODO: must d[i][i] = 0 : for(int j=0;j<N+1;j++) d[i][j] = MAX_TIME;

		for(int i=1;i<=N;i++){	
			int n;
			cin >> n;
			for(int j=0;j<n;j++){
				int contact, time;
				cin >> contact >> time;
				d[i][contact] = time;
			}
		}

		//floyd warshall
		floyd_warshall(d, N);
		//min max
		min_max(d, N);

		cin >> N;
	}
	return 0;
}

