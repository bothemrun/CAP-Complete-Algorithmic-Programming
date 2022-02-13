//uva133.cpp
#include<iostream>
#include<stdio.h>
#include<string.h> //memset()
using namespace std;

int main(){
	int N, k, m;
	cin >> N >> k >> m;
	while(N && k && m){
		bool out[N]; //0-based
		memset(out, false, sizeof(out));
		int pos = N - 1, neg = 0;
		int n = N;
		while(n > 0){
			for(int i=0;i<k;i++){
				while(true){
					pos = (pos + 1)%N;
					if(out[pos] == false)
						break;
				}
			}
			for(int i=0;i<m;i++){
				while(true){
					neg = (neg - 1 + N)%N;
					if(out[neg] == false)
						break;
				}
			}

			if(n != N)
				cout << ",";
			if(pos != neg){
				out[pos] = true;
				out[neg] = true;
				//output is 1-based
				printf("%3d", pos+1);
				printf("%3d", neg+1);
				n -= 2;
			}else{
				out[pos] = true;
				printf("%3d", pos+1);
				n -= 1;
			}
		}
		cout << "\n";
		cin >> N >> k >> m;
	}
	return 0;
}

