//poj2240.cpp
#include<iostream>
#include<string>
#include<unordered_map>
#include<utility>
#include<algorithm>
#include<string.h>
#define max_n 32
using namespace std;

inline void floyd_warshall(double d[][max_n], int n){
	for(int k=0;k<n;k++)
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)if(k != i && k != j && i != j) //floyd warshall probihits positive weighted cycle for max
		d[i][j] = max(d[i][j], d[i][k]*d[k][j]);
}

int main(){
	int n_case = 0;
	int n;
	cin >> n;
	while(n){
		double d[max_n][max_n];
		unordered_map<string, int> name2id;

		memset(d, 0, sizeof(d));
		for(int i=0;i<n;i++){
			string name;
			cin >> name;
			pair<string,int> p (name, i);
			name2id.insert(p);
		}

		int m;
		cin >> m;
		for(int i=0;i<m;i++){
			string name1, name2;
			double trans;
			cin >> name1 >> trans >> name2;
			unordered_map<string,int>::iterator c1 = name2id.find(name1);
			unordered_map<string,int>::iterator c2 = name2id.find(name2);
			d[c1->second][c2->second] = trans;
		}
		
		floyd_warshall(d, n);
		
		cout << "Case " << ++n_case << ": ";
		bool arbitrage = false;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)if(d[i][j]*d[j][i] > 1){ arbitrage = true; break; }
		if(arbitrage) cout << "Yes\n"; else cout << "No\n";
		
		cin >> n;
	}
	return 0;
}
