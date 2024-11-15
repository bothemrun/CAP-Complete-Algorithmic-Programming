//2031A.cpp
#include<iostream>
#include<vector>
#include<unordered_map>
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

		vector<int> h(n);
		for(int i=0;i<n;i++){
			cin>>h[i];
		}
		
		unordered_map<int,int> cnt;
		for(const int& x: h) cnt[x]++;

		int ans = n;
		for(const int& x: h){
			ans = min(ans, n - cnt[x]);
		}
		cout<<ans<<"\n";
	}

	return 0;
}

