//uva10158
#include<iostream>
#include<string.h>
using namespace std;

inline int set_find(int a,int set[]){
	if(set[a] == -1) return a;
	return (set[a] = set_find(set[a],set));
}

inline int relation(int a,int b,int set[],int n){
	if(set_find(a,set) == set_find(b,set)) return 1;//friends
	else if(set_find(a,set) == set_find(b+n,set)) return 0;//enemy
	else return 2;//undetermined
}

inline void set_join(int a,int b,int set[]){
	a = set_find(a,set);
	b = set_find(b,set);
	if(a != b) set[a] = b;
	//TODO: MLE / TLE : if(same root), then "set[root] = root", not "set[root] = (-1)"
	//TODO: set[ set_find(a,set) ] = set_find(b,set);
}

int main(){
	int n;
	cin >> n;

	int set[4+2*n];
	memset(set,-1,sizeof(set));

	int c, x, y;
	cin >> c >> x >> y;
	while(c || x || y){
		if(c == 1){
			if(relation(x,y,set,n) == 0){
				cout << "-1\n";//contradict
			}else{
				set_join(x,y,set);
				set_join(x+n,y+n,set);//An enemy of a friend is an enemy
			}
		}else if(c == 2){
			if(relation(x,y,set,n) == 1){
				cout << "-1\n";//contradict
			}else{
				set_join(x,y+n,set);
				set_join(x+n,y,set);
			}
		}else if(c == 3){
			if(relation(x,y,set,n) == 1) cout << "1\n";
			else cout << "0\n";
		}else if(c == 4){
			if(relation(x,y,set,n) == 0) cout << "1\n";
			else cout << "0\n";
		}
		
		cin >> c >> x >> y;
	}
	return 0;
}

