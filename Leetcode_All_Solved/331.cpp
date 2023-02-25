class Solution {
public:
    const string delim = ",";
    const string null = "#";
    inline void split(const string& preorder, vector<string>& serial, const string& delim){
        int end;
        int start = 0;
        while( (end = preorder.find(delim, start)) != string::npos){
            serial.push_back( preorder.substr(start, (end-1) - (start-1) ) );
            start = end + delim.size();
        }
        serial.push_back( preorder.substr(start) );
    }
    bool deserial(const vector<string>& serial, int& i){
        //NOTE: too few null
        if(!(i < serial.size())) return false;
        
        if(serial.at(i) == null){
            i++;
            return true;
        }

        //NOTE: too many null
        if(serial[i] == null)return false;
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
        //NOTE: too few null
        return ret && (i == serial.size());
    }
};
