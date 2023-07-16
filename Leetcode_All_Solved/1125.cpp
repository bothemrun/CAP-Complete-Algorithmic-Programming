//m0
//bitmask dp. recursion with memo.

//NOTE: traps:
//(1) 1LL << 40 for long long, not 1 << 40
//(2) __builtin_popcountll() for long long, not __builtin_popcount()


//use mask to represent a team. use gcc __builtin_popcount ,
//which is standard c++ after c++20.

#define diff_set(a, b) ( a & (~b) )

#define notyet (-1)
#define NONE LLONG_MAX

#include<limits.h>
#include<unordered_map>

class Solution {
public:
    int m, n;
    unordered_map<string, int> skill2i;
    vector<int> people2skill;


    vector<vector<long long>> memo;

    long long choose_or_not_skill2team_mask(const int& i, const int& skill_mask){

        if(skill_mask == 0) return 0;
        if(i < 0) return NONE;

        if(memo[i][skill_mask] != notyet) return memo[i][skill_mask];

        long long not_choose = choose_or_not_skill2team_mask(i-1, skill_mask);

        
        int smaller_mask = diff_set( skill_mask, people2skill[i] );
        long long choose = NONE;
        //NOTE: trap: smaller_mask != skill_mask
        if(smaller_mask != skill_mask){

            choose = choose_or_not_skill2team_mask(i-1, smaller_mask);

            //NOTE: trap: (1 << i) for long long
            if(choose != NONE)
                choose |= (1LL << i);
        }

        //NOTE: trap: __builtin_popcountll() for long long
        //int popcount0 = __builtin_popcount(not_choose);
        //int popcount1 = __builtin_popcount(choose);
        int popcount0 = __builtin_popcountll(not_choose);
        int popcount1 = __builtin_popcountll(choose);

        return memo[i][skill_mask] = (popcount0 <= popcount1)? not_choose:choose;
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        //1. preprocess req_skills mask
        m = req_skills.size();

        //all req_skills unique
        for(int i=0;i<m;i++)
            skill2i[ req_skills[i] ] = i;
        
        //2. preprocess people skillset mask
        n = people.size();
        people2skill.resize(n, 0);
        for(int i=0;i<n;i++)
            for(const string& skill: people[i] )if( skill2i.count(skill) != 0 )
                people2skill[i] |= ( 1 << skill2i[ skill ] );
        

        //3. bitmask dp to get team mask
        //(1<<m) - 1 covers all required skills
        memo.resize(n, vector<long long>(1<<m, notyet) );
        long long team_mask = choose_or_not_skill2team_mask(n-1, (1<<m) - 1 );

        //4. get team vector
        vector<int> team_vec;
        for(int i=0;i<n;i++){
            if(team_mask%2 == 1) team_vec.push_back(i);

            team_mask >>= 1;
        }

        return team_vec;
    }
};
