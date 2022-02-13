//uva10583
#include<iostream>
#include<string.h>
using namespace std;

inline int set_find(int a, int set[]){
	if(set[a] == (-1)) return a;
	return (set[a] = set_find(set[a], set));
}

inline void set_join(int a, int b, int set[]){
	a = set_find(a, set);
	b = set_find(b, set);
	if(a != b) set[a] = b;
}

int main(){
	int n_case = 0;
	int n, m;
	cin >> n >> m;
	while(n && m){
		int set[n+1];
		memset(set, (-1), sizeof(set));

		for(int i=0;i<m;i++){
			int a, b;
			cin >> a >> b;
			set_join(a, b, set);
		}

		int ans = 0;
		for(int i=1;i<=n;i++)if(set[i] == (-1)) ans++;
		cout << "Case " << ++n_case << ": ";
		cout << ans << "\n";

		cin >> n >> m;
	}
	return 0;
}

