//poj2013
#include<iostream>
#include<string>
using namespace std;

void print(int n){
	string top, bottom;
	if(n == 0) return;
	else if(n >= 2){
		cin >> top >> bottom;
		cout << top << "\n";
		print(n-2);
		cout << bottom << "\n";
	}else{
		cin >> top;
		cout << top << "\n";
	}
}

int main(){
	int n_set = 0;
	int n;
	cin >> n;
	while(n != 0){
		cout << "SET " << ++n_set << "\n";
		print(n);

		cin >> n;
	}
	return 0;
}

