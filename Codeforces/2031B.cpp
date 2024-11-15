//2031B.cpp
#include<iostream>
#include<vector>
using namespace std;

static auto _ = [](){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

int main(){
	int t;
	cin>>t;
	for(int tt=0;tt<t;tt++){
		int n;
		cin>>n;

		vector<int> p(n);
		for(int i=0;i<n;i++) cin>>p[i];

		bool good = true;
		for(int i=0;i+1<n;i++){
			if( p[i]==i+1 ){
				continue;
			}
			if( p[i]==i+2 && p[i+1]==i+1 ){
				swap( p[i], p[i+1] );
				continue;
			}
			good = false;
			break;
		}
		if(good) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

