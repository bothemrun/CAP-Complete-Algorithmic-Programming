# O(logn)
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        def binary_upwards(nums: list[int], low: int, high: int) -> int:
            if(low == high):
                return low
            
            mid = (high+low)//2
            # since nums[i] != nums[i+1]
            # mid+1 < n, already ruled out by if low == high
            if(nums[mid] < nums[mid+1]):
                return binary_upwards(nums, mid+1, high)
            else:
                return binary_upwards(nums, low, mid)
        
        return binary_upwards(nums, 0, len(nums)-1)
