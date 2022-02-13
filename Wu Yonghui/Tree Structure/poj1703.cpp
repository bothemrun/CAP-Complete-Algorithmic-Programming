//poj1703
#include<iostream>
#include<string.h>
using namespace std;

inline int set_find(int a,int set[]){
	if(set[a] == -1) return a;
	return (set[a] = set_find(set[a],set));
}

inline void set_join(int a,int b,int set[]){
	a = set_find(a,set);
	b = set_find(b,set);
	if(a != b) set[a] = b;
	//TODO: MLE : if(same root), then "set[root] = root", not "set[root] = (-1)"
	//TODO: set[ set_find(a,set) ] = set_find(b,set);
}

int main(){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		int N, M;
		cin >> N >> M;
		char cmd;
		int a, b;

		int set[4+N*2];
		memset(set, -1, sizeof(set));

		for(int i=0;i<M;i++){
			cin >> cmd >> a >> b;
			if(cmd == 'D'){
				set_join(a, b+N, set);
				set_join(a+N, b, set);
			}else if(cmd == 'A'){
				if(set_find(a,set) == set_find(b,set)) cout << "In the same gang.\n";
				else if(set_find(a,set) == set_find(b+N,set)) cout << "In different gangs.\n";
				else cout << "Not sure yet.\n";
			}else{ cerr << "Wrong input!!\n"; return 1; }
		}
	}//for t
	return 0;
}

