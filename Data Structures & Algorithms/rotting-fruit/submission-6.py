class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        time, fresh = 0, 0
        q = deque()
        visit = set()

        directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        for r in range(row):
            for c in range(col):
                if grid[r][c] == 2:
                    q.append((r, c))
                    visit.add((r, c))
                elif grid[r][c] == 1:
                    fresh += 1

        while q and fresh > 0:
            for _ in range(len(q)):
                r, c = q.popleft()

                for dr, dc in directions:
                    cr, cc = r + dr, c + dc

                    if (cr < 0 or cr >= row or cc < 0 or cc >= col or (cr, cc) in visit):
                        continue

                    if grid[cr][cc] == 1:
                        grid[cr][cc] = 2
                        q.append((cr, cc))
                        visit.add((cr, cc))
                        fresh -= 1

            time += 1
        

        return time if fresh == 0 else -1