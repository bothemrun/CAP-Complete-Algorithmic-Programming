//2031D.cpp
//[A] observation: prefix & suffix:
//1. to land on prefix trees --> max of prefix trees
//2. to land on suffix trees --> this is the key.

//[B]
//1. bad way: among all suffix trees < a[i], find max ans from them.
//2. DP: get dp(i) from dp(i+1) --> don't know how to come up with the idea.


//[C] the key for suffix trees is the strategy:
//1. jump backward to the highest tree in the prefix [0, i], including itself
//2. jump forward to the lowest tree in the suffix [i+1, n-1]
//3. then we surely can jump backward to [i+1]
//4. for implementations --> just check if we can do step 2. -->
//5. just check if prefix max[0, i] > suffix min[i+1, n-1]

#include<vector>
#include<iostream>
using namespace std;

static auto _ = [](){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

int main(){
	int t;
	cin>>t;
	for(int T=0;T<t;T++){
		int n;
		cin>>n;

		vector<int> a(n);
		for(int i=0;i<n;i++) cin>>a[i];

		vector<int> pref_max(n);
		pref_max.front() = a.front();
		for(int i=1;i<n;i++) pref_max[i] = max( a[i], pref_max[i-1] );

		vector<int> suf_min(n);
		suf_min.back() = a.back();
		for(int i=n-2;i>=0;i--) suf_min[i] = min( a[i], suf_min[i+1] );


		vector<int> dp(n);
		dp.back() = pref_max.back();

		for(int i=n-2;i>=0;i--){
			dp[i] = pref_max[i];

			if( pref_max[i] > suf_min[i+1] ){
				dp[i] = max( dp[i], dp[i+1] );
			}
		}

		for(int i=0;i<n;i++) cout<<dp[i]<<( (i==n-1)? "\n":" " );
	}
	return 0;
}

