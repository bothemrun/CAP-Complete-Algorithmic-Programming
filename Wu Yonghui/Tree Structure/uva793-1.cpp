//uva793
#include<iostream>
#include<string.h>
#include<string>
#include<sstream>
#include<ctype.h>
using namespace std;

inline int set_find(int a, int set[]){
	if(set[a] == -1) return a;
	return (set[a] = set_find(set[a], set));
}

inline void set_join(int a, int b, int set[]){
	a = set_find(a, set);
	b = set_find(b, set);
	if(a != b) set[a] = b;
}

int main(){
	int T;
	cin >> T;
	int n;
	bool n_from_last = false;
	string cmd;
	for(int t=0;t<T;t++){
		int success = 0;
		int fail = 0;

		if(n_from_last == false) cin >> n;
		else{
			stringstream ss(cmd);
			ss >> n;
			n_from_last = false;
		}

		int set[n+1];
		memset(set, -1, sizeof(set));

		do{
			cmd = "";
			cin >> cmd;
			cout << cmd << ":cmd\n";
			if(isdigit(cmd[0])){
				n_from_last = true;
				break;
			}

			int a, b;
			cin >> a >> b;
			if(cmd == "c"){ set_join(a, b, set);
				cout << "c " << a << " " << b << "\n";
			}else if(cmd == "q"){
				cout << "q " << a << " " << b << "\n";
				if(set_find(a, set) == set_find(b, set)) success++;
				else fail++;
			}
			else{ cerr << "wrong input!!!\n\n\n"; return 1;}
			
			cout << cin.eof() << ":eof\n";
		}while(!cin.eof());

		cout << success << "," << fail << "\n\n";

		cout << "\n\n";
	}//t
	return 0;
}

