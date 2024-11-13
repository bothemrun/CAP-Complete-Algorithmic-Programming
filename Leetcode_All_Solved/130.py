# O(mn)
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])
        visited = [[False for j in range(n)] for i in range(m)]
        di = [1, 0, -1, 0]
        dj = [0, 1, 0, -1]
        

        def dfs(i: int, j: int, capture: bool) -> None:
            if(not(0<=i and i<m and 0<=j and j<n)):
                return

            if(visited[i][j] == True or board[i][j] != "O"):
                return
            visited[i][j] = True

            if(capture == True):
                board[i][j] = "X"
            
            for a, b in zip(di, dj):
                dfs(i+a, j+b, capture)
            return


        def check(i: int, j: int, capture: bool) -> None:
            if(visited[i][j] == False and board[i][j] == "O"):
                dfs(i, j, capture)
        
        for i in range(m):
            check(i, 0, False)
            check(i, n-1, False)
        for j in range(n):
            check(0, j, False)
            check(m-1, j, False)
        
        for i in range(1, m-1):
            for j in range(1, n-1):
                check(i, j, True)
        return
