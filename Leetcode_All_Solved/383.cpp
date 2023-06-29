#include<unordered_map>
#include<utility>
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> count;
        for(int i=0;i<magazine.size();i++){
            unordered_map<char,int>::iterator f = count.find(magazine.at(i));
            if(f == count.end()){
                pair<char,int> p (magazine.at(i), 1);
                count.insert(p);
            }else
                f->second++;
        }
        
        for(int i=0;i<ransomNote.size();i++){
            unordered_map<char,int>::iterator f = count.find(ransomNote.at(i));
            if(f == count.end())
                return false;
            else if(f->second == 0)
                return false;
            else
                f->second--;
        }
        return true;
    }
};
