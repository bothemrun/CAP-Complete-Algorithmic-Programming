//uva10608
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

inline void make_set(int set[], int set_size[], int n){
	//memset(set, (-1), sizeof(set));
	memset(set, (-1), sizeof(int)*(n+1));
	for(int i=1;i<=n;i++) set_size[i] = 1;
}

inline int set_find(int p, int set[]){
	if(set[p] == (-1)) return p;
	return (set[p] = set_find(set[p], set));
}

inline void set_join(int a, int b, int set[], int set_size[]){
	a = set_find(a, set);
	b = set_find(b, set);
	if(a != b){
		set[a] = b;
		set_size[b] += set_size[a];
	}
}

int main(){
	int t;
	cin >> t;
	for(int tt=0;tt<t;tt++){
		int n, m;
		cin >> n >> m;
		
		int set[n+1];
		int set_size[n+1];
		//memset(set, (-1), sizeof(set));
		//XXX: memset(set_size, 1, sizeof(set_size));
		//XXX: We can use memset() to set all values as 0 or -1 for integral data types also. It will not work if we use it to set as other values. The reason is simple, memset works byte by byte.  
		//XXX: https://www.geeksforgeeks.org/memset-in-cpp/
		make_set(set, set_size, n);

		int a, b;
		for(int i=0;i<m;i++){
			cin >> a >> b;
			set_join(a, b, set, set_size);
		}

		int max_size = 0;
		for(int i=1;i<=n;i++) max_size = max(max_size, set_size[i]);
		cout << max_size << "\n";
	}
	return 0;
}

