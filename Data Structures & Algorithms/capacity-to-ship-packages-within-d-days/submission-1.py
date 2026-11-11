class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        l = max(weights)
        r = sum(weights)
        res = r

        def canShip(cap):
            ships, currentCap = 1, cap
            for w in weights:
                if currentCap - w < 0:
                    ships += 1
                    if ships > days:
                        return False
                    currentCap = cap

                currentCap -= w
            return True
        
        while l <= r:
            cap = (l + r) // 2
            if canShip(cap):
                res = min(res, cap)
                r = cap - 1
            else:
                l = cap + 1

        return res
