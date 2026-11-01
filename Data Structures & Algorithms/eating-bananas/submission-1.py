class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r, re = 1, max(piles), 0

        def canEat(k):
            bananas = 0
            for pile in piles:
                bananas += math.ceil(pile / k)
            return bananas <= h

        while l <= r:
            mid = (l + r) // 2
            if (canEat(mid)):
                re = mid
                r = mid - 1
            else:
                l = mid + 1
        return re
        