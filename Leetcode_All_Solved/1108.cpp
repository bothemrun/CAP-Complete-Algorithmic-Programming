class Solution {
public:
    string defangIPaddr(string address) {
        string defang = "";
        for(const char& c: address){
            if(c == '.') defang += "[.]";
            else defang += c;
        }
        return defang;
    }
};
