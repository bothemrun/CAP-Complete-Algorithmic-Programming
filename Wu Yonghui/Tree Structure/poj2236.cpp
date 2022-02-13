//poj2236
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

inline void make_set(int set[], int N){
	for(int i=1;i<=N;i++) set[i] = i;
}

int set_find(int p, int set[]){
	if(set[p] == p) return p;
	return (set[p] = set_find(set[p], set));
}

inline void set_join(int p, int q, int set[]){
	p = set_find(p, set);
	q = set_find(q, set);
	if(p != q){
		set[p] = q;
	}
}

int main(){
	int N, d;
	cin >> N >> d;
	int x[N+1], y[N+1];
	for(int i=1;i<=N;i++) cin >> x[i] >> y[i];

	int dis[N+1][N+1];
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++) dis[i][j] = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);

	int set[N+1];
	make_set(set, N);
	int repaired[N+1];
	memset(repaired, 0, sizeof(repaired));

	while(!cin.eof()){
		string cmd;
		cin >> cmd;
		if(cmd == "O"){
			int p;
			cin >> p;
			repaired[p] = 1;
			for(int i=1;i<=N;i++)if(i != p && dis[i][p] <= d*d && repaired[i]) set_join(i, p, set);
		}else if(cmd == "S"){
			int p, q;
			cin >> p >> q;
			if(set_find(p, set) == set_find(q, set)) cout << "SUCCESS\n";
			else cout << "FAIL\n";
		}//TODO else return 1;
	}
	return 0;
}

