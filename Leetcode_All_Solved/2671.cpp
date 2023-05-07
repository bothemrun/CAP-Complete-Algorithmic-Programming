#define max_fre ((int)1e5 + 2)
#define max_num ((int)1e5 + 2)
class FrequencyTracker {
public:
    int num2fre[max_num] = {0};
    int fre2numcnt[max_fre] = {0};
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        int old_fre = num2fre[number];
        num2fre[number]++;
        
        //only remove if originally not empty
        if(old_fre != 0) fre2numcnt[ old_fre ]--;
        
        //add
        fre2numcnt[ num2fre[number] ]++;
    }
    
    void deleteOne(int number) {
        int old_fre = num2fre[number];
        if(old_fre == 0) return;
        num2fre[number]--;
        
        //remove, already checked if empty
        fre2numcnt[ old_fre ]--;
        
        //add
        fre2numcnt[ num2fre[number] ]++;
    }
    
    bool hasFrequency(int frequency) {
        return fre2numcnt[ frequency ] != 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
