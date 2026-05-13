class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        tes = set(nums)
        longest = 0
        for num in nums:
            if num - 1 not in tes:
                off = 0
                while (True):
                    if num + off not in tes: break
                    off += 1

                longest = off if off > longest else longest
        return longest