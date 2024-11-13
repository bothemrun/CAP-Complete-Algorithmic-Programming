from bisect import bisect_left, bisect_right

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left = bisect_left(nums, target, 0, len(nums))
        right = bisect_right(nums, target, 0, len(nums)) - 1
        return [left, right] if(left <= right) else [-1, -1]
