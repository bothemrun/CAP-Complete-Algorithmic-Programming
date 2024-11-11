//914C.cpp
//leetcode 3352 Count K-Reducible Numbers Less Than N hard

//[A] the key is "after 1 operation, x <= s.length = 1000"
//1. use dp: f(x) = f( popcount(x) ) + 1

//[B] proof that reduced x < x --> will we get infinite loops?
//1. x = sum{ bit_i * 2^i }
//2. reduced x = sum{ bit_i * 1 }
//3. hence reduced x must < x. QED.

//[C] from 0 to 1 operation --> digit DP
//1. dp(i, cnt1, tight)

//[D] edge case for x=1, k=0:
//1. correct for k>=1. but for k>=0, wrong.
//2. in the base case of DP recursion.

//O(s.length) + O(s.length^2 * digit range) = O(1000^2 * 2) = 2e6

#include<vector>
#include<iostream>
#include<limits.h>
using namespace std;

static auto _ = [](){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

const int impossible = INT_MAX - 10;
const int notyet = (-1);
const int mod = (int)1e9 + 7;
vector<int> brute_memo;
vector<vector<vector<int>>> memo;
int k;
int len;

int brute(const int x){
	if(x==0) return impossible;
	if(x==1) return 0;

	if(brute_memo[x] != notyet) return brute_memo[x];

	return brute_memo[x] = 1 + brute( __builtin_popcount(x) );
}

int digit_dp2brute(const string& s, int i, int cnt1, bool tight){
	//[D] edge case for x=1, k=0:
	//1. correct for k>=1. but for k>=0, wrong.
	if(i==len-1 && cnt1==0){
		//for 00...00? --> 1 or 0
		//so check if s is "00..001" or "00..000" to see if 1 is k-reducible
		return 0 == k;//for x = 1
	}
	if(i==len){
		//[D] edge case for x=1, k=0:
		//1. correct for k>=1. but for k>=0, wrong.
		return 1 + brute(cnt1) == k; //for cnt1==0, impossible.
	}

	if(memo[i][cnt1][tight] != notyet) return memo[i][cnt1][tight];

	int ret = 0;
	const int bound = (tight)? (s[i] == '1'):1;
	for(int digit=0;digit<=bound;digit++){
		ret = (
			ret + digit_dp2brute(s, i+1, cnt1 + (digit==1), tight && digit==bound)
		)%mod;
	}
	return memo[i][cnt1][tight] = ret;
}

int main(int argc, char* argv[]){
	string s;
	cin>>s;
	cin>>k;

	len = s.size();
	//don't have to set a memo of size max s.length = 801.
	//[B] proof that reduced x < x --> will we get infinite loops?
	brute_memo.resize(len + 1, notyet);
	memo.resize(len, vector<vector<int>>(len + 1, vector<int>(2, notyet) ) );
	cout<<digit_dp2brute(s, 0, 0, true)<<"\n";

	return 0;
}

