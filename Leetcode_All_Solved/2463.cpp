//recusion with memo

//[A] order
//1. sort robots & factories by positions
//2. if robot[i] < robot[j] & factory[x][0] < factory[y][0],
//3. then it's optimal to assign them by the order, not the reversed order.


//[B] then partition dp problem
//1. 813. Largest Sum of Averages medium
//2. 1105. Filling Bookcase Shelves medium


//[C] preprocessing
//1. partition sum of robots[i~j] moving to partition[x]



//O(total parts * total robots covered * max limit) 
//+ O(F * R^2)
//= O(F * R * limit) + O(F*R^2) 
//= O(100^3) = O(1e6)

#include<algorithm>
#include<stdlib.h>

class Solution {
public:
    const long long notyet = (-1);
    const long long impossible = LLONG_MAX;
    vector<vector<long long>> memo;

    vector<vector<vector<long long>>> partition_sum;

    long long enum_last_partition(const vector<int>& robot, const vector<vector<int>>& factory, const int& i, const int& part){

        if(!(i>=0)) return 0;

        assert(part>=0);

        if(part==0){
            if(i+1 > factory[part][1]) return impossible;

            return partition_sum[part][0][i];
        }

        if(memo[i][part] != notyet) return memo[i][part];

        //this part covers nothing.
        long long mi = enum_last_partition(robot, factory, i, part-1);

        for(int len=1;len<=factory[part][1];len++){
            //this part covers [part_front, i]
            int part_front = i - (len-1);
            if(!(part_front >= 0)) break;

            long long pre_partition = enum_last_partition(robot, factory, part_front-1, part-1);
            if(pre_partition == impossible) continue;

            mi = min(
                mi,
                pre_partition +
                partition_sum[part][part_front][i]
            );
        }

        return memo[i][part] = mi;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int part_n = factory.size();

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());


        //max limit <= robot.length
        partition_sum.resize(part_n, vector<vector<long long>>(n, vector<long long>(n) ) );

        for(int part=0;part<part_n;part++){
            for(int i=0;i<n;i++){
                long long sum = 0;

                for(int len=1;len<=factory[part][1];len++){
                    int j = i + (len-1);
                    if(!(j<n)) break;

                    sum += abs( robot[j] - factory[part][0] );

                    partition_sum[part][i][j] = sum;
                }
            }
        }


        memo.resize(n, vector<long long>(part_n, notyet));
        return enum_last_partition(robot, factory, n-1, part_n-1);
    }
};
