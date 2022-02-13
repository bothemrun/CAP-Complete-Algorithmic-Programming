//poj3750
#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h> //memset()
using namespace std;

int main(){
	int N;
	cin >> N;
	string name[N+1]; //all 1-based
	for(int i=1;i<=N;i++)
		cin >> name[i];
	int W, S;
	scanf("%d,%d", &W, &S);

	bool out[N+1];
	//memset(out, 0, sizeof(out));
	memset(out, false, sizeof(out));
	int cur = W-1;
	for(int n=N;n>0;n--){
		for(int count=1;count<=S;count++){
			while(true){
				//XXX: 1-based mod cur = (cur+1)%N + 1;
				cur = (cur + 1)%N;
				if(cur == 0) cur = N;
				if(out[cur] == false)
					break;
			}
		}

		out[cur] = true;
		cout << name[cur] << "\n";
	}
	return 0;
}

