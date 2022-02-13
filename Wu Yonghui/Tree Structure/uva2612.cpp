//uva2612 //TODO?
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

inline int max_set_size(int set[],int n){
}

int main(){
	int n;
	cin >> n;
	while(n){
		int set[3+2*n];
		memset(set,-1,sizeof(set));
		bool consistent = true;
		int i;
		for(i=1;i<=n;i++){
			string sen,is,truth;
			int j;
			cin >> sen >> j >> is >> truth;
			if(truth == "true."){
				if(set_find(i,set) == set_find(j+n,set)){
					consistent = false;
					break;
				}
				set_join(i,j,set);
				set_join(i+n,j+n,set);//XXX: enemies of a friend are enemies
			}else if(truth == "false."){
				if(set_find(i,set) == set_find(j,set)){
					consistent = false;
					break;
				}
				set_join(i,j+n,set);
				set_join(i+n,j,set);
			}else{cerr << "Wrong input!\n";return 1;}
		}//for i

		if(consistent = false){
			for(;i<=n;i++){ //clear input
				string sen,is,truth; int j; cin >> sen >> j >> is >> truth;
			}
			cout << "Inconsistent\n";
		}else cout << max_set_size(set,n) << "\n";

		cin >> n;
	}
	return 0;
}

