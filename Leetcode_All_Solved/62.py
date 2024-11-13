class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        mod = 2 * 10**9

        @cache
        def enum_path(i: int, j: int) -> int:
            if(i==0 or j==0):
                return 1
            
            return enum_path(i-1, j) + enum_path(i, j-1)
        
        return enum_path(m-1, n-1)%mod
