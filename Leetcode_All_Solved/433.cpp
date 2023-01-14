#include<queue>
#include<unordered_map>
#include<unordered_set>
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankset;
        for(auto& key: bank)
            bankset.insert(key);
        
        bankset.insert(start);
        
        vector<char> mutation = {'A', 'T', 'C', 'G'};

        unordered_map<string, int> visited2d;
        queue<string> q;
        q.push(start);
        visited2d[start] = 0;
        
        while(q.size() != 0){
            string gene = q.front();
            q.pop();
            if(gene == end)return visited2d[gene];

            for(int i=0;i<8;i++){
                for(const char& mutate: mutation)if(gene[i] != mutate){
                    string mutated_gene = gene;
                    mutated_gene[i] = mutate;
                    if(bankset.count(mutated_gene) == 0) continue;
                    if(visited2d.count(mutated_gene) != 0) continue;

                    visited2d[mutated_gene] = visited2d[gene] + 1;
                    q.push(mutated_gene);
                }
            }
        }

        return (-1);
    }
};
