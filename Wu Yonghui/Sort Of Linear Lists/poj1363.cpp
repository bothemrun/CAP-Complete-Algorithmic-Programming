//poj1363
#include<iostream>
#include<stack>
#define MAX_N 1005
using namespace std;

inline void deplete_stack(stack<int>& st, int B[], int& b){
	while(st.size() != 0 && st.top() == B[b]){
		b++;
		st.pop();
	}
}

int main(){
	int N;
	int B[MAX_N];
	cin >> N;
	while(N != 0){
		cin >> B[0];
		while(B[0] != 0){
			for(int i=1;i<N;i++) cin >> B[i];
			
			stack<int> st;
			int b = 0;
			for(int a=1;a<=N;a++){
				//1 element from A per loop
				//now stack is depleted : B[b] != st.top()
				if(B[b] == a){
					b++;
					deplete_stack(st, B, b);
				}else st.push(a);
			}

			deplete_stack(st, B, b);
			if(st.size() != 0) cout << "No\n";
			else cout << "Yes\n";

			cin >> B[0];
		}

		cin >> N;
		if(N != 0) cout << "\n";
	}
	return 0;
}

