class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        visited = [False for i in range(n)]

        al = [[] for i in range(n)]
        for i in range(n):
            for j in range(i+1, n):
                if(isConnected[i][j]):
                    al[i].append(j)
                    al[j].append(i)
        
        def dfs(al: List[List[int]], u: int) -> None:
            if(visited[u] == True):
                return
            visited[u] = True

            for v in al[u]:
                dfs(al, v)
            return

        component = 0
        for i in range(n):
            if(visited[i] == False):
                dfs(al, i)
                component += 1
        return component
