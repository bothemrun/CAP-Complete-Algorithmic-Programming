class Solution {
public:
    inline void split(const string& s, vector<int>& v, const string delim="."){
        int start = 0, end;
        while( (end = s.find(delim, start)) != string::npos){
            v.push_back( stoi( s.substr(start, (end-1) - (start-1) ) ) );

            start = end + delim.size();
        }

        if(start<s.size()) v.push_back( stoi( s.substr(start) ) );
    }

    inline bool trailing0(const vector<int>& v, int begin){
        for(int i=begin;i<(int)v.size();i++)if(v[i] != 0) return false;
        return true;
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        split(version1, v1);
        split(version2, v2);

        int m = v1.size();
        int n = v2.size();
        for(int i=0;i<min(m,n);i++)if(v1[i] != v2[i]){
            return (v1[i] < v2[i])? (-1):1;
        }

        if(m==n) return 0;

        if(m>n) return (trailing0(v1, n)==true)? 0:1;
        return (trailing0(v2, m)==true)? 0:(-1);
    }
};
