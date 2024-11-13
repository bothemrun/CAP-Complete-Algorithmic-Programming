# O(n^2) for partition DP / DP Interval
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        word_set = set()
        for word in wordDict:
            word_set.add(word)
        
        @cache
        def enum_partition(i: int) -> bool:
            if(i==len(s)):
                return True
            
            subs = ""
            for j in range(i, len(s)):
                subs += s[j]
                if(subs not in word_set):
                    continue
                
                if(enum_partition(j+1) == True):
                    return True
            return False
        
        return enum_partition(0)
