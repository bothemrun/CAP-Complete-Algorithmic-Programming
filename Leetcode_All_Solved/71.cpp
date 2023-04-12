class Solution {
public:
    inline void split(const string& s, vector<string>& v, const string& delim="/"){
        int start = 0, end;
        while( (end = s.find(delim, start)) != string::npos ){
            //root /, repeated /
            if(start != end) v.push_back(s.substr(start, (end-1) - (start-1) ));
            start = end + delim.size();
        }
        //no trailing /
        if(start < s.size()) v.push_back(s.substr(start));
    }
    string simplifyPath(string path) {
        vector<string> path_v;
        split(path, path_v);

        vector<string> cano_v;
        for(const string& dir: path_v){
            if(dir == ".") continue;
            else if(dir == ".."){
                //NOTE: edge case: check size
                if(cano_v.size() > 0) cano_v.pop_back();
            }else cano_v.push_back(dir);
        }

        string cano = "";
        for(const string& dir: cano_v)
            cano += "/" + dir;
        //NOTE: edge case:
        if(cano == "") cano = "/";
        return cano;
    }
};
