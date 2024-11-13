from collections import deque

class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        # edge case
        if(grid[0][0] == 1):
            return (-1)

        n = len(grid)
        di = [1, 0, -1, 0,  1, 1, -1, -1]
        dj = [0, 1, 0, -1,  1, -1, -1, 1]

        q = deque()
        ever2q = [[False for j in range(n)] for i in range(n)]
        q.append((0, 0))
        ever2q[0][0] = True

        level = 0
        while(len(q) != 0):
            level += 1

            lsize = len(q)
            for l in range(lsize):
                i, j = q[0]
                q.popleft()

                if(i==n-1 and j==n-1):
                    return level
                
                for a, b in zip(di, dj):
                    x = i+a
                    y = j+b
                    if(not(0<=x and x<n and 0<=y and y<n)):
                        continue
                    if(ever2q[x][y] == True):
                        continue

                    if(grid[x][y] != 0):
                        continue
                    
                    q.append((x, y))
                    ever2q[x][y] = True
        # end while
        return (-1)
