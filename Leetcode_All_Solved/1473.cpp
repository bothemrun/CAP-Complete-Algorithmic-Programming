//m0
//recursion with memo

//[brute force method: enumerate partition]
//1. for a house index and a target, enumerate the color and the neighborhoood (this partition) for the house.
//2. O(house * target * (color * house) ) = O(mm * nm) = O(m^3 * n) = O(100^3 * 20) = O(2e7)

//[last house color]
//1. keep the last house color in recursion / memo
//2. then enumerate this house's color
//3. check with last house color --> neighborhoods + 1 or + 0.
//4. O(house * target * color * (color) ) = O( (mn)^2 ) = O(2000^2) = O(4e6)

#define notyet (-1)
#define impossible INT_MAX
#include<limits.h>
#include<algorithm>

class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> memo;

    //count a new neighborhood when this house's color != last house color
    //so it works for i == m
    int check_last_color(const vector<int>& houses, const vector<vector<int>>& cost, const int& i, const int& neighborhood, const int& last_color){

        if(i == m)
            return (neighborhood == 0)? 0:impossible;
        
        //NOTE:
        if(neighborhood < 0) return impossible;
        

        if(memo[i][neighborhood][last_color] != notyet) return memo[i][neighborhood][last_color];


        if(houses[i] != 0){
            int next_neighborhood = neighborhood;
            if(last_color != houses[i]) next_neighborhood--;

            return memo[i][neighborhood][last_color] = check_last_color(houses, cost, i+1, next_neighborhood, houses[i] );
        }

        
        int min_cost = impossible;
        for(int color=1;color<=n;color++){

            int next_neighborhood = neighborhood;

            if(last_color != color) next_neighborhood--;

            int next_cost = check_last_color(houses, cost, i+1, next_neighborhood, color);

            if(next_cost != impossible)
                min_cost = min(min_cost, next_cost + cost[i][color - 1] );
        }

        return memo[i][neighborhood][last_color] = min_cost;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        this->m = m;
        this->n = n;

        memo.resize(m, vector<vector<int>>(target + 1, vector<int>(n + 1, notyet) ) );
        
        int ret = check_last_color(houses, cost, 0, target, 0);
        return (ret == impossible)? (-1):ret;
    }
};
