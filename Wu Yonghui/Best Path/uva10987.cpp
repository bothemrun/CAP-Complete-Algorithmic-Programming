//uva10987
#include<iostream>
#include<algorithm>
#include<vector>
#define max_n 100
#define max_latency (100*10000)
using namespace std;

struct Edge{
	int from, to;
	Edge(int from_,int to_){
		from = min(from_,to_);
		to = max(from_,to_);
	}
	Edge(){}
};

bool cmp(const struct Edge& e1, const struct Edge& e2){
	if(e1.from != e2.from) return e1.from < e2.from;
	return e1.to < e2.to;
}

inline void adj_matrix(int d[][max_n+1], int n){
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) d[i][j] = (i == j)? 0:max_latency;

	for(int i=1;i<=n-1;i++)
	for(int j=1;j<=i;j++){
		int latency;
		cin >> latency;
		d[i+1][j] = latency;
		d[j][i+1] = latency;
	}
}

inline void anti_floyd_warshall(int d[][max_n+1], int n, vector<struct Edge>& edges){
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++){
		bool need_direct_cable = true;
		for(int k=1;k<=n;k++)if(k != i && k != j){
			if(d[i][j] > d[i][k] + d[k][j]){
				cout << "Need better measurements.\n";
				edges.clear();
				return;
			}
			if(d[i][j] == d[i][k] + d[k][j]) need_direct_cable = false;
		}

		if(need_direct_cable) edges.push_back( Edge(i, j) );
	}
}

inline void print(vector<struct Edge>& edges, int d[][max_n+1]){
	if(edges.size() == 0) return;
	cout << edges.size() << "\n";
	sort(edges.begin(), edges.end(), cmp);
	for(vector<struct Edge>::iterator it = edges.begin();it != edges.end();it++)
		cout << it->from << " " << it->to << " " << d[it->from][it->to] << "\n";
}

int main(){
	int N; //num of testcases
	cin >> N;
	for(int t=1;t<=N;t++){
		cout << "Case #" << t << ":\n";
		int n;
		cin >> n;//num of computers

		//adj matrix
		int d[max_n+1][max_n+1];
		adj_matrix(d, n);

		//anti floyd warshall
		vector<struct Edge> edges;
		anti_floyd_warshall(d, n, edges);
		
		print(edges, d);
		cout << "\n";
	}
	return 0;
}

