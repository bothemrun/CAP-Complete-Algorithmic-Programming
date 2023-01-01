#include<algorithm>
#include<unordered_set>
// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>

class Solution {
public:
    vector<bool> prime;
    vector<int> all_prime;
    
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
	for (int p=2; p<=n; p++)
	if (prime[p])
		all_prime.push_back(p); //cout << p << " ";
}
    
    int distinctPrimeFactors(vector<int>& nums) {
        int max_ele = *max_element(nums.begin(), nums.end());
        prime = vector<bool>(max_ele + 1, true);
        SieveOfEratosthenes(max_ele);
        
        unordered_set<int> factor;
        for(const int& num: nums){
            for(const int& p: all_prime)if(num % p == 0){
                if(factor.count(p) == 0){
                    factor.insert(p);
                }
            }
        }
        return factor.size();
    }
};
