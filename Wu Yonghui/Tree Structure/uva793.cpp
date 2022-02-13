//uva793
//bad input format
#include<iostream>
#include<string.h>
#include<string>
#include<ctype.h>
#include<sstream>
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
	for(int t=0;t<T;t++){
		int n;
		string line;
		while(getline(cin, line)) if(line.size() != 0 && isdigit(line[0])){
			stringstream ss(line);
			ss >> n;
			break;
		}

		int success = 0, fail = 0;
		int set[n+1];
		memset(set, -1, sizeof(set));
		while(1){
			getline(cin, line);
			if(cin.eof() || line.size() == 0 || !isalnum(line[0])) break;

			char cmd;
			int a, b;
			stringstream ss(line);
			ss >> cmd >> a >> b;
			if(cmd == 'c'){
				set_join(a, b, set);
			}else if(cmd == 'q'){
				if(set_find(a, set) == set_find(b, set)) success++;
				else fail++;
			}else{ cerr << "Input Error!!\n"; return 1; }
		}//while(1)

		//TODO: cout << success << "," << fail << "\n\n";
		cout << success << "," << fail << "\n";
		if(t != T-1) cout << "\n";
	}//for t
	return 0;
}

