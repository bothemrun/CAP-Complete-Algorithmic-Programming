//m0

//[A] if k==1:
//1. --> choose a prefix substring & append it at the end.
//2. O(n^2) brute force enumeration

//[B] if k > 1:
//1. proof: we can swap any neighbors --> then we can get any permutation.
//2. original: abc[xy]de
//3. for any k (k==1 or not), we can always rotate.
//4. so [xy]de abc
//5. break the order: [x]de abc[y]
//6. de abc [yx]
//7. then rotates back: abc [yx] de

//O(n^2) overall

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1){
            sort(s.begin(), s.end());
            return s;
        }

        int n = s.size();
        string ans = s;
        for(int i=0;i+1<n;i++){
            ans = min(
                ans,
                s.substr(i+1) + s.substr(0, i - (0-1))
            );
        }
        return ans;
    }
};
