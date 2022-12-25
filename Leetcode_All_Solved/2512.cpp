#include<unordered_set>
#include<sstream>
#include<algorithm>
bool cmp_fn(const vector<int>& a, const vector<int>& b){
    if(a[0] != b[0])return a[0] > b[0];//descending
    else return a[1] < b[1];//ascending
}

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> pos;
        unordered_set<string> neg;
        for(const string& s: positive_feedback){
            pos.insert(s);
        }
        for(const string& s: negative_feedback){
            neg.insert(s);
        }
        
        int n = report.size();
        vector<vector<int>> point(n, vector<int>(2, 0));
        for(int i=0;i<n;i++){
            point[i][1] = student_id[i];
            
            istringstream ss(report[i]);
            string word;
            while(ss >> word){
                if(pos.count(word) != 0){
                    point[i][0] += 3;
                }else if(neg.count(word) != 0){
                    point[i][0] -= 1;
                }
            }
        }
        
        sort(point.begin(), point.end(), cmp_fn);
        vector<int> ans(k);
        for(int i=0;i<k;i++){
            ans[i] = point[i][1];
        }
        return ans;
    }
};
