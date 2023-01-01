#include<algorithm>
#include<limits.h>
// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>

class Solution {
public:
    
    vector<bool> prime;
    vector<int> all_prime;
    int left;
    
    void SieveOfEratosthenes(int n)
{
	// Create a boolean array "prime[0..n]" and initialize
	// all entries it as true. A value in prime[i] will
	// finally be false if i is Not a prime, else true.
	
    //bool prime[n+1];
	//memset(prime, true, sizeof(prime));

	for (int p=2; p*p<=n; p++)
	{
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true)
		{
			// Update all multiples of p
			for (int i=p*2; i<=n; i += p)
				prime[i] = false;
		}
	}

	// Print all prime numbers
	//for (int p=2; p<=n; p++)
    for (int p=max(left, 2); p<=n; p++){
	    if (prime[p]){
		    all_prime.push_back(p); //cout << p << " ";
        }
    }
}
    
    vector<int> closestPrimes(int left, int right) {
        prime = vector<bool>(right + 1, true);
        this->left = left;
        SieveOfEratosthenes(right);
        
        int min_diff = INT_MAX;
        int num1 = (-1);
        int num2 = (-1);
        //cout <<all_prime.size()<<" loop: "<<endl;
        
        int psize = all_prime.size();
        //for(int i=0;i<all_prime.size()-1;i++){
        for(int i=0;i+1<psize;i++){
            //cout << all_prime[i]<<" ";
            
            if(min_diff > all_prime[i+1] - all_prime[i]){
                //NOTE: for ==, choose the smaller num1
                min_diff = all_prime[i+1] - all_prime[i];
                num1 = all_prime[i];
                num2 = all_prime[i+1];
            }
        }
        //cout<<"now ans\n";
        
        vector<int> ans = {num1, num2};
        return ans;
    }
};
