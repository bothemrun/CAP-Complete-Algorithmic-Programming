class Solution {
public:
    const string delim = ",";
    const string null = "#";
    inline void split(const string& s, vector<string>& serial, const string& delim){
        int start = 0, end;
        while( (end = s.find(delim, start)) != string::npos){
            serial.push_back( s.substr(start, (end-1) - (start-1) ) );
            start = end + delim.size();
        }
        if(start < s.size()) serial.push_back( s.substr(start) );
    }
    bool deserial(const vector<string>& serial, int& i){
        //too few null
        if(!(i < serial.size())) return false;

        if(serial[i] == null){
            i++;
            return true;
        }

        i++;
        if( deserial(serial, i) == false)return false;
        if( deserial(serial, i) == false)return false;
        return true;
    }
    bool isValidSerialization(string preorder) {
        vector<string> serial;
        split(preorder, serial, delim);

        int i = 0;
        bool ret = deserial(serial, i);

        //remaining at the end
        return ret && i == serial.size();
    }
};
