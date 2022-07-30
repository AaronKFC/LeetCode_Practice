class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        rowNum, colNum = len(grid), len(grid[0])
        visited = set()
        islandNum = 0
        directions = [[1,0], [0,1], [-1,0], [0,-1]]
        
        def bfs(r,c):
            q = collections.deque()
            visited.add((r,c))
            q.append((r,c))
            while q:
                row, col = q.popleft()
                for dr, dc in directions:
                    r, c = row+dr, col+dc
                    if (r in range(rowNum) and
                        c in range(colNum) and
                        grid[r][c] == '1' and
                        (r,c) not in visited):
                        q.append((r,c))
                        visited.add((r,c))
        
        for r in range(rowNum):
            for c in range(colNum):
                if grid[r][c] == '1' and (r,c) not in visited:
                    bfs(r,c)
                    islandNum += 1
        return islandNum