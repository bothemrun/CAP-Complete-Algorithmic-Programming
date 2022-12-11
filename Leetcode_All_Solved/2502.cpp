class Allocator {
public:
    int max_mID = 1000+2;
    vector<vector<int>> mID2mem;
    vector<int> mem;
    int mem_n;
    Allocator(int n) {
        mem_n = n;
        mem = vector<int>(mem_n, 0);
        mID2mem = vector<vector<int>>(max_mID, vector<int>());
    }
    
    int allocate(int size, int mID) {
        for(int m=0;m<mem_n;m++)if(mem[m] == 0){
            int cnt = 0;
            int low = m;
            while(m+1 < mem_n && mem[m+1] == 0){
                cnt++;
                m++;
            }
            //now m on the last 0 or last element in mem, all 0 winthin
            //now m is the high of 0's window
            int high = m;
            int len = high - (low-1);
            if(len >= size){
                for(int k=0;k<size;k++){
                    mem[low + k] = 1;
                    mID2mem[mID].push_back(low + k);
                }
                return low;
            }
        }
        
        //not found
        return (-1);
    }
    
    int free(int mID) {
        int cnt = 0;
        for(int m: mID2mem[mID]){
            cnt++;
            mem[m] = 0;
        }
        mID2mem[mID].clear();
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
