//poj1861.cpp
//https://math.stackexchange.com/questions/2229041/graph-theory-how-to-prove-this-statement
//we want to find a spanning tree that it's maximum edge-weight is minimum. Prove that each MST (Minimum Spanning Tree) is an answer to this problem
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;

int set_find(int a, int set[]){
	if(set[a] == -1) return a;
	return (set[a] = set_find(set[a], set));
}

inline void set_join(int a, int b, int set[]){
	set[ set_find(a, set) ] = set_find(b, set);
}

struct Edge{
	int from, to;
	int d;
	Edge(int from_,int to_,int d_){from=from_;to=to_;d=d_;}
};

bool cmp(const struct Edge& e1, const struct Edge& e2){return e1.d <= e2.d;}
bool cmp_edge_id(const struct Edge& e1, const struct Edge& e2){
	if(e1.from != e2.from) return e1.from < e2.from;
	return e1.to < e2.to;
}

int main(){
	int N, M;
	cin >> N >> M;

	vector<struct Edge> edges;
	for(int i=0;i<M;i++){
		int a, b, d_;
		cin >> a >> b >> d_;
		edges.push_back(Edge(min(a,b), max(a,b), d_));
	}

	//Kruskal
	sort(edges.begin(), edges.end(), cmp);
	int set[1+N];
	memset(set,-1,sizeof(set));
	vector<struct Edge> mst;
	int n_mst_edge = 0;
	for(vector<struct Edge>::iterator it = edges.begin();it != edges.end();it++)if(set_find(it->from, set) != set_find(it->to, set)){
		mst.push_back(*it);
		set_join(it->from, it->to, set);
		if(++n_mst_edge == N-1) break;
	}

	//
	cout << mst.back().d << "\n" << N-1 << "\n";
	sort(mst.begin(), mst.end(), cmp_edge_id);
	for(vector<struct Edge>::iterator it=mst.begin();it != mst.end();it++) cout << it->from << " " << it->to << "\n";

	return 0;
}


