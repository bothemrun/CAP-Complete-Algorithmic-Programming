//poj2421
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;


struct Edge{
	int from, to;
	int d;

	Edge(int from_,int to_,int d_){from=from_;to=to_;d=d_;}
};

bool cmp(const struct Edge& e1, const struct Edge& e2){return e1.d <= e2.d;}

int set_find(int a, int set[]){
	if(set[a] == -1) return a;
	return (set[a] = set_find(set[a], set));
}

inline void set_join(int a, int b, int set[]){
	//TODO: Wrong: Illegal Mem Access / Seg Fault / MLE 
	//TODO: if(same root) then "set[root] = root", not "set[root] = (-1)"
	//TODO: set[ set_find(a,set) ] = set_find(b,set);
	a = set_find(a,set);
	b = set_find(b,set);
	if(a != b) set[a] = b;
}

int main(){
	int N;
	cin >> N;

	int set[N+1];
	memset(set,-1,sizeof(set));

	vector<struct Edge> edges;

	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++){
		int d_;
		cin >> d_;
		if(i != j) edges.push_back(Edge(i,j,d_));
	}

	int Q;
	cin >> Q;
	for(int i=0;i<Q;i++){
		int a, b;
		cin >> a >> b;
		set_join(a,b,set);
	}

	//Kruskal
	sort(edges.begin(), edges.end(), cmp);
	int ans = 0;
	for(vector<struct Edge>::iterator it=edges.begin();it != edges.end();it++)
		if(set_find(it->from,set) != set_find(it->to,set)){
			set_join(it->from,it->to,set);
			ans += it->d;
		}
	cout << ans << "\n";
	return 0;
}

