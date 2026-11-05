class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        row, col = len(heights), len(heights[0])
        pac, atl = set(), set()
        res = []

        def iterate(ocean, r, c, rp, cp):
            if (r < 0 or r >= row or c < 0 or c >= col or heights[rp][cp] > heights[r][c] or (r, c) in ocean):
                return

            ocean.add((r, c))

            iterate(ocean, r + 1, c, r, c)
            iterate(ocean, r, c + 1, r, c)
            iterate(ocean, r - 1, c, r, c)
            iterate(ocean, r, c - 1, r, c)

        for r in range(row):
            iterate(pac, r, 0, r, 0)
            iterate(atl, r, col - 1, r, col - 1)

        for c in range(col):
            iterate(pac, 0, c, 0, c)
            iterate(atl, row - 1, c, row - 1, c)

        for cell in pac:
            if cell in atl:
                res.append([cell[0], cell[1]])
        
        return res